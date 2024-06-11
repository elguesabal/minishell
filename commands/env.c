#include "../minishell.h"

void	env(char **env, t_str **env_list)
{
	if (env == NULL)
		return ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	variable_status(0, env_list);
}
