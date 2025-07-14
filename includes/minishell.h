/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagwu <dagwu@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:48:53 by dagwu             #+#    #+#             */
/*   Updated: 2025/06/27 17:24:41 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

typedef struct s_dat
{
	struct s_var	*var;
	struct s_env	*env;
	struct s_arg	*arg;
	int				iter;
	int				arg_count;
	char			**vec_str;
	char			**env_str;
}					t_dat;
//
typedef struct s_var
{
	int				i;
	int				j;
}					t_var;
//
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;
//
typedef struct s_arg
{
	char			*value;
	struct s_arg	*next;
}					t_arg;

void				ft_sigint_handler(int sig);
void				ft_sigquit_handler(int sig);
// void	ft_initialise_sigaction(struct sigaction *sa, void (*f)(int));
void				ft_set_up_sigactions(void);
void				ft_new_export_node(t_dat *data, char *name, char *val);
void				ft_export(t_dat *data, const char *assignment, char *name,
						char *val);
// void				ft_unset(t_dat *data, const char *key);
void				ft_env(t_dat *data);
void				ft_echo(t_dat *data);
void				ft_exit(t_dat *data);
void				ft_cd_chdir(const char *path);
void				ft_cd(t_dat *data, const char *path);
void				ft_handle_builtin(t_dat *data);
void				ft_free_string_array(char **arr);
t_env				*init_env_list(char **envp);
t_arg				*parse_args(char **argv);
t_dat				*init_shell_data(char **argv, char **envp);
int					ft_strisspace(char *str);
int					ft_isspace(char c);

// additions
char				**copy_env(char **envp);
void				free_env(char **env);
void				ft_pwd(t_dat *data);
void				ft_export_simple(t_dat *data, char *assignment);
void				ft_export_with_update(t_dat *data, char *assignment);
void				ft_unset(t_dat *data, char *var_name);

// piping
int					execute_pipeline(char ***commands);
#endif
