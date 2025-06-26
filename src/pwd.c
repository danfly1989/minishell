/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:31:22 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/26 19:34:20 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_dat *data)
{
	char	*cwd;

	(void)data; //suppressed to respect header
	cwd = getcwd(NULL, 0);
	if(cwd == NULL)
	{
		perror("pwd");
		return;
	}
	ft_printf("%s\n", cwd);
		free(cwd);
}
