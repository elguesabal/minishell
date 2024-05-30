#include "../minishell.h"

void	init_less_than(char **args)
{
	int	fd;
// printf("args[0][0]: %s\n", args[0]);

	while (*args && args[0][0] != '<')
		args++;
// printf("args[0][0]: %s\n", args[0]);
	fd = open(args[1], O_RDONLY);
	if (fd == -1)
		printf("-minishel: %s: Arquivo ou diretório inexistente\n", args[1]);
	else
		dup2(fd, STDIN_FILENO);
	close(fd);
}

void	finish_less_than(int new_stdin)
{
	dup2(new_stdin, STDIN_FILENO);
// printf("new_stdin: %d\n", new_stdin);
	// close(new_stdin); // E SE EU QUISER USAR ELE EM OUTRO COMANDO?
}
