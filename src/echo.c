#include "minishell.h"

void	ft_echo(t_dat *data)
{
	t_arg	*arg;
	int		newline;

	arg = data->arg->next; // skip echo command
	newline = 1;
	// check for -n
	if (arg && ft_strncmp(arg->value, "-n", 3) == 0)
	{
		newline = 0;
		arg = arg->next;
	}
	while (arg)
	{
		printf("%s", arg->value);
		if (arg->next)
			printf(" ");
		arg = arg->next;
	}
	if (newline)
		printf("\n");
}
