#include "../minishell.h"

void	init_bigger_then(char **args)
{
	int	fd;

	while (*args && args[0][0] != '>')
		args++;
	fd = open(args[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	// if ()
	// {
	// 	???
	// }
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	finish_bigger_then(int new_stdout)
{
	dup2(new_stdout, STDOUT_FILENO);
}
