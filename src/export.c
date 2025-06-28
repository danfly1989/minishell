/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:31:05 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/27 14:00:33 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_var_count(char **env)
{
	int	count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}
/*clear former variable and create new on in its stead with
the same name (assignment)*/
static void	update_env_var(t_dat *data, int i, char *assignment)
{
	char	*new_value;

	new_value = ft_strdup(assignment);
	if (!new_value)
		return ;
	free((char *)data->env_str[i]);
	data->env_str[i] = new_value;
}

/*add a new variable to the end of the env list*/
static void	append_new_var(t_dat *data, char *assignment)
{
	char	**new_env;
	int		count;
	int		i;

	count = env_var_count(data->env_str);
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return ;
	i = 0;
	while (i < count)
	{
		new_env[i] = (char *)data->env_str[i];
		i++;
	}
	new_env[count] = ft_strdup(assignment);
	if (!new_env[count])
	{
		free(new_env);
		return ;
	}
	new_env[count + 1] = NULL;
	free(data->env_str);
	data->env_str = new_env;
}

/*scan through the env_str array. If existing is found, update it
and return 1. If no existing found, return 0*/
static int	find_existing_var(t_dat *data, char *assignment, size_t len)
{
	int		i;
	char	*existing_var;

	i = 0;
	while (data->env_str[i])
	{
		existing_var = (char *)data->env_str[i];
		if (ft_strncmp(existing_var, assignment, len) == 0
			&& existing_var[len] == '=')
		{
			update_env_var(data, i, assignment);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
 *export takes the argument assignment and checks if it contains the =
 operator. Returns immediately if not found. If an existing var with
 the same name as the left side is found, it will return. If the name
 does not already exist within env, it will create a new one
 * */
void	ft_export_with_update(t_dat *data, char *assignment)
{
	char	*equals_pos;
	size_t	name_len;

	if (!assignment || !data)
		return ;
	equals_pos = ft_strchr(assignment, '=');
	if (!equals_pos)
		return ;
	name_len = equals_pos - assignment;
	if (find_existing_var(data, assignment, name_len))
		return ;
	append_new_var(data, assignment);
}
