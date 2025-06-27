/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:19:51 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/27 14:19:54 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Using the LL style arg struct, start from arg after header
(skipping echo itself). There will be a newline appended by default
at the endunless -n is found as second argument.
Iterate through list and print all arguments*/
void	ft_echo(t_dat *data)
{
	t_arg	*arg;
	int		newline;

	arg = data->arg->next;
	newline = 1;
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
