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
