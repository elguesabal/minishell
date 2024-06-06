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

int	count_args(char **args)
{
	int	i;

	while (args[i] && args[i][0] != '|')
		i++;
	return (i);
}

char	**args_pipe(char **argv, int process) // ESSA FUNCAO DEVE RETORNAR OS ARGUMRNTOS CORRETAMENTE PARA O PROXIMO PROCESSO
{
(void)argv;
(void)process;
	char	**return_arg;
	int	i;
	int	j;
(void)return_arg;

	i = 0;
	while (argv[i] && i < process)
	{
		while (argv[i] && argv[i][0] != '|')
		{
			i++;
		}
		i++; // ATE ENCONTRAR O PIPE RELATIVO AO process
	}
	return_arg = malloc((count_args(&argv[i]) + 1) * sizeof(char *));
	j = 0;
	while (argv[i] && argv[i][0] != '|')
	{
		return_arg[j] = argv[i];
		j++;
		i++;
	}
	return_arg[j] = NULL;
// printf("process: %d\n", process);
// i = 0;
// while (argv[i])
// {
// 	printf("argv[%d]: %s\n", i, argv[i]);
// 	i++;
// }
// i = 0;
// while (return_arg[i])
// {
// 	printf("return_arg[%d]: %s\n", i, return_arg[i]);
// 	i++;
// }
	return (return_arg);
}

void	command_pipe(char *str, char **argv, char ***argenv, t_str **env_list)
{
	pid_t	pid[2];
	int	fd[2];
	int	n_pipe;
	int	i;
	char	**args_process;

	// int	index;
// printf("parei antes de fazer o pipe()\n");
// return ;
	pipe(fd);

	n_pipe = count_pipe(argv);
// printf("n_pipe: %d\n", n_pipe);
// printf("str: %s\n", str);
// i = 0;
// while (argv[i])
// {
// 	printf("argv[%d]: %s\n", i, argv[i]);
// 	i++;
// }

	i = 0;
	while (i <= n_pipe)
	{
		pid[i] = fork();

// printf("i: %d\n", i);
// char	teste = i + 48;
// if (pid[i] == 0)
// {
// 	write(1, &teste, 1);
// 	write(1, "\n", 1);
// 	// printf("processo filho %d\n", i);
// }

		if (pid[i] == 0)
		{
// printf("i == %d\n", i);
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
(void)args_process;
// int	j = 0;
// while (argv[j])
// {
// 	printf("argv[%d]: %s\n", j, argv[j]);
// 	j++;
// }
// exit(0);

			// commands(str, &argv[i], argenv, env_list);
			// exit_shell(argv, str, *argenv, env_list);


				// TROCAR ESSE TRECHO DE CODIGO PELA FUNCAO redirection_operators()
// 			if (i == 0)	// AKI EU POSSO FAZER UMA FUNCAO Q DEPENDENDO DO VALOR DE i ELE VAI PEGANDO ARGUMENTOS APOS O NUMERO DE i DO PIPE
// 			{
// // printf("i == 0\n");
// 				char	*teste[] = {"ls", "-all", NULL};
// 				execve("/bin/ls", teste, NULL);
// 			}
// 			else if (i == 1)
// 			{
// // printf("i == 1\n");
// 				char	*teste[] = {"wc", "-l", NULL};
// 				execve("/bin/wc", teste, NULL);
// 			}
// 			exit_shell(argv, str, *argenv, env_list);
				// TROCAR ESSE TRECHO DE CODIGO PELA FUNCAO redirection_operators()



			// args_process = args_pipe(argv, i);
			args_process = args_pipe(argv, i);
			// redirection_operators(str, args_process, argenv, env_list);
			exit(0);
// 			exit_shell(argv, str, *argenv, env_list);






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


// pid_t	init_pipe(int last) // AINDA PENSANDO COMO IMPLEMENTAR O PIPE // ACHO Q NAO DA PRA SEGUIR ESSA LINHA DE RACIOCINIO PQ OS PROCESSOS FILHOS VAI CONTINUAR NO LOOP E SE MULTIPLICAREM COMO UMA ARVORE
// {
// 	pid_t	pid;
// 	int	fd[2];

// 	pipe(fd);
// 	pid = fork();
// 	if (pid == 0) // FAZER O waitpid() SO NA FUNCAO DE FINISH
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		if (last)
// 			dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);
// 	}
// 	return (pid);
// }

// void	finish_pipe(int *fd, int *pid, t_str env_list)
// {
// 	int	status;

// 	close(fd[0]);
// 	close(fd[1]);
// 	while (*pid != 0)
// 	{
// 		waitpid(*pid, &status, 0);
// 		pid++;
// 	}
// 	if (WIFEXITED(status)) // AKI EU SO DEVO SALVAR O ULTIMO STATUS MESMO
// 	variable_status(WEXITSTATUS(status), env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
// }