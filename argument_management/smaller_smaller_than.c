#include "../minishell.h"

void	init_smaller_smaller_than(char **args, t_str **env_list)
{
	int	fd;
	char	*line;

	while (*args && args[0][0] != '<')
		args++;
	// fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC); // NAO SEI PQ ISSO AKI NAO DA CERTO NA HORA DE LER
	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR);
	// if ()
	// {
	// 	???
	// }

	while (1)
	{
		line = readline("> ");
		if (compare_str(args[1], line))
			break;
		line = environment_variable(line, env_list);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);

	close(fd);
	fd = open(".heredoc", O_RDONLY); // PQ RAIOS EU TENHO Q FECHAR E ABRIR PRA CONSEGUIR LER O Q EU MESMO ESCREVI??
	// if ()
	// {
	// 	???
	// }

// char buffer[100];
// printf("isso foi lido: %ld\n", read(fd, &buffer, 100));
// // printf("%s", buffer);

	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	finish_smaller_smaller_than(int new_stdin)
{
	dup2(new_stdin, STDIN_FILENO);
	// printf("new_stdin: %d\n", new_stdin);
	// close(new_stdin); // ESSE FD E FECHADO APOS O LOOP DE ARGUMENTOS // SERA Q TEM PROBLEMA FECHAR O MESMO FD DUAS VZS? // UE NAO ENTENDI PQ QUANDO EU ESCREVI ESSE CODIGO ACREDITAVA Q new_stdin TINHA O FD DO ARQUIVO .heredoc
	unlink(".heredoc");
}
