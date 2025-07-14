#include "minishell.h"
#include <signal.h>
#include <sys/wait.h>

static pid_t	*pids = NULL;
static int		pids_count = 0;

void	kill_children(void)
{
	for (int i = 0; i < pids_count; i++)
		kill(pids[i], SIGTERM);
}

int	execute_pipeline(char ***commands)
{
	int		i;
	int		in_fd;
	int		fd[2];
	pid_t	pid;
	int		status;
	int		exit_status;

	i = 0;
	in_fd = 0;
	// Count commands first
	while (commands[i])
		i++;
	pids_count = i;
	pids = malloc(sizeof(pid_t) * pids_count);
	if (!pids)
		return (-1); // malloc fail
	i = 0;
	while (commands[i])
	{
		if (commands[i + 1])
		{
			if (pipe(fd) == -1)
			{
				perror("pipe");
				kill_children();
				free(pids);
				return (-1);
			}
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			kill_children();
			free(pids);
			return (-1);
		}
		else if (pid == 0)
		{
			// Child process
			if (in_fd != 0)
			{
				dup2(in_fd, STDIN_FILENO);
				close(in_fd);
			}
			if (commands[i + 1])
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			execvp(commands[i][0], commands[i]);
			perror("execvp");
			exit(1);
		}
		else
		{
			// Parent process
			pids[i] = pid;
			if (in_fd != 0)
				close(in_fd);
			if (commands[i + 1])
			{
				close(fd[1]);
				in_fd = fd[0];
			}
		}
		i++;
	}
	// Wait for all children, get last command status
	status = 0;
	exit_status = 0;
	for (int j = 0; j < pids_count; j++)
	{
		if (waitpid(pids[j], &status, 0) == -1)
			perror("waitpid");
		else if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			exit_status = 128 + WTERMSIG(status);
			// Optionally print signal info here
		}
	}
	free(pids);
	return (exit_status);
}
