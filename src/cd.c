/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:02:03 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/27 17:26:36 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*A very simplisic cd function that uses chdir on definded
target path. If no path found, it will go to HOME, unless
home is not set. Print error when zero is not returned
(expected behaviour)*/
void	ft_cd(t_dat *data, const char *path)
{
	const char	*target;

	(void)data;
	if (path && *path)
		target = path;
	else
	{
		target = getenv("HOME");
		if (!target)
		{
			ft_printf("HOME NOT SET\n");
			return ;
		}
	}
	if (chdir(target) != 0)
		ft_printf("minishell: cd: %s: %s\n", target, strerror(errno));
}
