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
