#include "../minishell.h"

void	init_less_than(char **args)
{
	int	fd;

	while (*args && args[0][0] != '<')
		args++;
	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		printf("-minishel: %s: Arquivo ou diretório inexistente\n", args[1]);
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}
