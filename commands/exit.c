#include "../minishell.h"

void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	exit_shell(char **argv, char *str, char **env)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (argv)
	{
		free_split(argv);
		argv = NULL;
	}
	if (env)
	{
		free_split(env);
		env = NULL;
	}
	exit(0);
}
