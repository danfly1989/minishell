/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:18:54 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/27 14:18:55 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*a minimalistic void exit function that only
 * uses the struct parameter to follow the existing
 * header. The param is thus suppressed. Should be 
 * edited later*/
void	ft_exit(t_dat *data)
{
	(void)data;
	exit(0);
}
