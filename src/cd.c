/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:02:03 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/26 20:19:05 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_dat *data, const char *path)
{
	const char *target;
	(void) data;
	//determine targed directory
	if(path && *path)
		target = path;
	else
	{
		target = getenv("HOME");
		if(!target)
		{
			ft_printf("HOME NOT SET\n");
			return;
		}
	}
	if(chdir(target)!= 0)
		ft_printf("minishell: cd: %s: %s\n", target, strerror(errno));
	
}
