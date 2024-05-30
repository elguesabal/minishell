#include "../minishell.h"

void	less_than(char **args)
{
	int	fd;

(void)args;
	while (*args && args[0][0] == '<')
		args++;
	args += 2;
	fd = open(args[1], O_RDONLY); // args[1]
	if (fd == -1)
		printf("nao abriu\n");
	// else
		// printf("abriu\n");
	dup2(fd, STDIN_FILENO);
}
