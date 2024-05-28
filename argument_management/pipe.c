#include "../minishell.h"

// int	search_pipe(char **argv) // CAIU EM DESUSO POR CAUSA DA FUNCAO search_operator()
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] == '|')
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	count_pipe(char **argv)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

// char	**args_pipe(char **argv, int process)
// {
// 	char	**args_pipe;
// 	int	i;

// 	i = 0;
// 	while ()
// 	{

// 	}

// 	args_pipe = malloc( * sizeof(char *));

// 	i = 0;
// 	while (args_pipe[i])
// 	{
// 		if (search_char(argv[i])) // VERIFICAR SE HA PIPE DENTRO DA STRING
// 		{
// 			if (i == 0)
// 			{

// 			}
// 			else if (i > 0)
// 			{

// 			}
// 		}
// 		else
// 		{
// 			args_pipe[i] = copy_str(argv[i]);
// 		}

// 		i++;
// 	}
// 	return (args_pipe);
// }

void	command_pipe(char *str, char **argv, char ***argenv, t_str **env_list)
{
	pid_t	pid[2];
	int	fd[2];
	int	n_pipe;
	int	i;
	// char	**args_pipe;
	// int	index;

	pipe(fd);

	n_pipe = count_pipe(argv);
	i = 0;
	while (i <= n_pipe)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			if (i != n_pipe)
				dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);

			// FUNCAO QUE ORGANIZA OS ARGUMENTOS ()

// (void)args_pipe;
// printf("tamanho dos args: %d\n", len_args_operators(argv));
(void)str;
(void)argenv;
(void)env_list;
exit(0);

			// commands(str, &argv[i], argenv, env_list);
			// exit_shell(argv, str, *argenv, env_list);



			// if (i == 0)	// AKI EU POSSO FAZER UMA FUNCAO Q DEPENDENDO DO VALOR DE i ELE VAI PEGANDO ARGUMENTOS APOS O NUMERO DE i DO PIPE
			// {
			// 	char	*teste[] = {"ls", "-all", NULL};
			// 	execve("/bin/ls", teste, NULL);
			// }
			// else if (i == 1)
			// {
			// 	char	*teste[] = {"wc", "-l", NULL};
			// 	execve("/bin/wc", teste, NULL);
			// }
			// exit_shell(argv, str, *argenv, env_list);

								// PROCESSAMENTO DE DADOS
// char	*teste[] = {argv[index], argv[index + 1], NULL};
// char	path[8] = "/bin/";
// path[5] = argv[index][0];
// path[6] = argv[index][1];
// path[7] = '\0';

// // printf("teste: %s\n", path);

// execve(path, teste, NULL);
								// PROCESSAMENTO DE DADOS
		}
		i++;
	}

	close(fd[0]);
	close(fd[1]);
	while (i)
	{
		waitpid(pid[i], NULL, 0);
		i--;
	}
}