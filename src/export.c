/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:31:05 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/26 20:46:13 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_simple(t_dat *data, const char *assignment)
{
	//count existing variable
	int count = 0;
	while(data->env_str[count])
		++count;

	//allocate new array one bigger
	char **new_env = malloc(sizeof(char *) * (count+2));
	if(!new_env)
		return;

	//copy pointers over
	int i = 0;
	while(i < count)
	{
		
		new_env[i] = (char *)data->env_str[i];
		i++;
	}

	//duplicate teh assignment string
	new_env[count] = ft_strdup(assignment);
	new_env[count + 1] = NULL;

	//swap in
	free((char **)data->env_str);
	data->env_str = (const char **)new_env;
}
