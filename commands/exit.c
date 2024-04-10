#include "../minishell.h"

void	free_argv(char **argv)
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

void	exit_shell(char **argv, char *str)
{
	free(str);
	free_argv(argv);
	exit(0);
}
