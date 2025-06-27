/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:31:22 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/27 14:21:00 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*a very minimalistic function using the
cwd function to retreive the working directory.
Prints error and returns on fail
Otherwise, it will print the string returned
by cwd. This one feels like cheating.*/
void	ft_pwd(t_dat *data)
{
	char	*cwd;

	(void)data;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("pwd");
		return ;
	}
	ft_printf("%s\n", cwd);
	free(cwd);
}
