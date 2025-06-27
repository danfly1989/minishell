/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:20:47 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/27 16:21:59 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*If var_name exists within env, remove it from
the 2d env array within the data struct. (env_str).
Only the line which matches will be freed. It will
otherwise iterate through the 2d array until finished
and return*/
void	ft_unset(t_dat *data, char *var_name)
{
	size_t		name_len;
	int			i;
	const char	*existing_var;
	bool		names_match;
	bool		has_equals;

	if (!var_name || !data)
		return ;
	name_len = ft_strlen(var_name);
	i = 0;
	while (data->env_str[i])
	{
		existing_var = data->env_str[i];
		names_match = (ft_strncmp(existing_var, var_name, name_len) == 0);
		has_equals = (existing_var[name_len] == '=');
		if (names_match && has_equals)
		{
			free((char *)data->env_str[i]);
			while (data->env_str[i])
			{
				data->env_str[i] = data->env_str[i + 1];
				i++;
			}
			return ;
		}
		i++;
	}
}
