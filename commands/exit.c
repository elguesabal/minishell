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

void	exit_shell(char **argv, char *str)
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
	exit(0);
}
