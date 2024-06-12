#include "../minishell.h"

/// @brief CONTA QUANTOS PROCESSOS TEM EM argv
/// @param argv ARRAY COM TODAS AS STRINGS (COMANDO, ARGUMENTOS E OPERADORES DE REDIRECIONAMENTO)
/// @return RETORNA A QUANTIDADE DE PROCESSOS TEM NO ARRAY
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

/// @brief ALLOCA MEMORIA PARA A QUANTIDADE DE FILE DESCRIPTIONS E USA A FUNCAO pipe() EM CADA UM DELES
/// @param n_process NUMERO DE FILE DESCRIPTIONS A SEREM ALOCADO NA MEMORIA
/// @return RETORNA O ENDERECO DE MEMORIA COM OS FILE DESCRIPTIONS
int	**init_fd(int n_process)
{
	int	**fd;
	int	i;

	fd = malloc(n_process * sizeof(int *));
	if (fd == NULL)
		return (NULL);
	i = 0;
	while (i < n_process)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (fd[i] == NULL)
			return (NULL);
		pipe(fd[i]);
		i++;
	}
	return (fd);
}

/// @brief FECHA ARRAY COM PARES DE FILE DESCRIPTIONS ABERTOS 
/// @param fd ARRAY COM TODOS OS FILE DESCRIPTIONS
/// @param n_process NUMERO DE FILE DESCRIPTIONS A SEREM FECHADOS
void	close_fds(int **fd, int n_process)
{
	int	i;

	i = 0;
	while (i < n_process)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

/// @brief CONTA QUANTOS ARGUMENTOS O PROCESSO ATUAL TEM
/// @param args ARRAY COM TODOS OS ARGUMENTOS APARTIR DO PROCESSO ATUAL
/// @return RETORNA A QUANTIDADE DE ARGUMENTOS DO PROCESSO ATUAL
int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] && args[i][0] != '|')
		i++;
	return (i);
}

/// @brief REDIRECIONA A ENTRADA E SAIDA PADRAO PARA OUTRO PROCESSO (A ENTRADA DO PROCESSO ATUAL E REDIRECIONADA PARA A SAIDA DO PROCESSO ANTERIOR E A SAIDA DO ATUAL E REDIRECIONADA PARA A ENTRADA DO PROXIMO PROCESSO)
/// @param current_process INTEIRO CORRESPONDENTE AO PROCESSO ATUAL
/// @param fd ARRAY COM TODOS FILE DESCRIPTOR
/// @param n_process NUMERO DE PROCESSOS
void	redirection_pipe(int current_process, int **fd, int n_process)
{
	if (current_process > 0)
		dup2(fd[current_process - 1][0], STDIN_FILENO);
	if (current_process < n_process)
		dup2(fd[current_process][1], STDOUT_FILENO);
	close_fds(fd, n_process);
}

/// @brief RECEBE OS ARGUMENTOS COM TODOS OS PROCESSO E COM BASE NO PROCESSO ATUAL RETORNA APENAS OS ARGUMENTOS DO PROCESSO ATUAL
/// @param argv ARRAY COM TODOS ARGUMENTOS E COMANDOS
/// @param process NUMERO DO PROCESSO ATUAL
/// @return RETORNA APENAS OS ARGUMENTOS DO PROCESSO ATUAL
char	**args_pipe(char **argv, int process)
{
	char	**return_arg;
	int		current_process;
	int		i;
	int		j;

	current_process = 0;
	i = 0;
	while (argv[i] && current_process != process)
	{
		if (argv[i] && argv[i][0] == '|')
			current_process++;
		i++;
	}
	return_arg = malloc((count_args(&argv[i]) + 1) * sizeof(char *));
	j = 0;
	while (argv[i] && argv[i][0] != '|')
	{
		return_arg[j] = copy_str(argv[i]);
		j++;
		i++;
	}
	return_arg[j] = NULL;
	return (return_arg);
}

/// @brief EXECUTA O COMANDO VERIFICANDO SE HA ALGUM OPERADOR DE REDIRECIONAMENTO E LIBERA MEMORIA CASO  A FUNCAO execve() NAO MATE O PROCESSO
/// @param str STRING RETORNADA POR readline()
/// @param args_process ARRAY DE STRING COM OS ARGUMENTOS DO ATUAL PROCESSO
/// @param argenv ARRAY DE STRING COM AS VARIAVEIS DE AMBIENTE EXPORTADAS
/// @param env_list LISTA ENCADEADA COM TODAS AS VARIAVEIS DE AMBIENTE (EXPORTADAS E NAO EXPORTADAS)
void	execute_process(char *str, char **args_process, char ***argenv, t_str **env_list)
{
	if (search_operator(args_process, '>') || search_operator(args_process, '<'))
		redirection_operators(str, args_process, argenv, env_list);
	else
	{
		revert_caracter(args_process);
		commands(str, args_process, argenv, env_list);
	}
	free_split(args_process);
}

/// @brief FINALIZA A FUNCAO command_pipe() USANDO close() EM TODOS OS FDS NO PROCESSO PAI E USANDO free() EM TODOS OS PONTEIRO DO PROCESSO
/// @param fd ARRAI DE FILE DESCRIPTIONS
/// @param n_process NUMERO DE PIPES
/// @param pid ARRAY COM TODOS OS PIDS DOS PROCESSOS FILHOS
void	finish_pipe(int **fd, int n_process, pid_t *pid)
{
	int	i;

	close_fds(fd, n_process);
	i = 0;
	while (i < n_process)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
	i = 0;
	while(i <= n_process)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	free(pid);
}

void	command_pipe(char *str, char **argv, char ***argenv, t_str **env_list)
{
	pid_t	*pid;
	int		**fd;
	int		n_process;
	int		i;

	n_process = count_pipe(argv);
	pid = malloc((n_process + 1) * sizeof(pid_t));
	fd = init_fd(n_process);
	if (pid == NULL || fd == NULL)
		return ;
	i = 0;
	while (i <= n_process)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			redirection_pipe(i, fd, n_process);
			execute_process(str, args_pipe(argv, i), argenv, env_list);
			exit_shell(argv, str, *argenv, env_list);
		}
		i++;
	}
	finish_pipe(fd, n_process, pid);
}
