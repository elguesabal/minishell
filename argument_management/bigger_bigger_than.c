#include "../minishell.h"

void	init_bigger_bigger_than(char **args)
{
	int	fd;

	while (*args && args[0][0] != '>')
		args++;
	fd = open(args[1], O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
