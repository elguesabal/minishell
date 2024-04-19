#include "../minishell.h"

void	env(char **env)
{
	if (env == NULL)
		return ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
