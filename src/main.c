#include "minishell.h"

char	**copy_env(char **envp)
{
	int		i;
	int		count;
	char	**copy;

	count = 0;
	while (envp[count])
		count++;
	copy = malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < count)
	{
		copy[i] = ft_strdup(envp[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

int	main(int argc, char **argv, char **envp)
{
	char	**my_env;
	t_dat	data;

	(void)argc;
	(void)argv;
	ft_printf("\n----------Main function launched-----------\n");
	my_env = copy_env(envp);
	if (!my_env)
		return (1); // handling alloc failure
	// using data struct to test copied env
	data.env_str = (const char **)my_env;
	t_arg echo_cmd, arg1, arg2, arg3;
	// set up linked list: echo -n Hello World
	data.arg = &echo_cmd;
	echo_cmd.value = "echo";
	echo_cmd.next = &arg1;
	arg1.value = "-n";
	arg1.next = &arg2;
	arg2.value = "Hello";
	arg2.next = &arg3;
	arg3.value = "World!";
	arg3.next = NULL;
	ft_echo(&data);
	fflush(stdout);
	ft_printf("\n ----end of echo test\n");
	// end echo testing, begin env testing
	ft_printf("\n--------begin env test-------");
	ft_env(&data);
	ft_printf("\n-------end of env test----------\n");
	// pwd test. Could be void
	ft_printf("\n--------begin pwd test-----------\n");
	ft_pwd(&data);
	ft_printf("---------end pwd test---------------\n");
	// begin change directory test
	ft_printf("\n-----------begin cd test-----------\n");
	ft_cd(&data, "/this/is/a/completely/invalid/filepath");
	ft_cd(&data, "/home/bocal");
	ft_printf("-----------end cd test----------\n");
	// begin the export test
	ft_printf("\n ---------export test begins------------\n");
	ft_export_simple(&data, "FOO=bar");
	ft_env(&data);
	ft_printf("-------end of export test-------------");
	// end the export test
	// free the copy of env variables
	free_env((char **)data.env_str);
	// exit test. Also could be void
	ft_printf("\n--------running exit--------");
	ft_exit(&data);
	return (0);
}
