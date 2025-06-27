/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:02:24 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/26 19:05:16 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*This function will simply print every
string in env_string in the env_str 2d array
line by line. It is important that env_str
is in fact correctly defined to reference
penv or a copy thereof before this function
is called.*/
void	ft_env(t_dat *data)
{
	int	i;

	i = 0;
	if (!data->env_str)
		return ;
	while (data->env_str[i])
	{
		ft_printf("%s\n", data->env_str[i]);
		i++;
	}
}
