#include "../minishell.h"

void	error_message(char *message, char *arg, int status, t_str **env_list)
{
	printf(message, arg);
	variable_status(status, env_list);
}
