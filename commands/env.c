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

	// printf("%s\n", env[0]);
	// printf("%s\n", env[1]);
	// printf("%s\n", env[2]);
	// printf("%s\n", env[3]);
	// printf("%s\n", env[4]);
	// if (env)
	// 	printf("teste: %p\n", env);
}
