/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:11:13 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:11:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
/// @param argv ARRAY DE STRING COM OS ARGUMENTOS DO ATUAL PROCESSO
/// @param arge ARRAY DE STRING COM AS VARIAVEIS DE AMBIENTE EXPORTADAS
/// @param env LISTA ENCADEADA COM TODAS AS VARIAVEIS DE AMBIENTE (EXPORTADAS E NAO EXPORTADAS)
void	execute_process(char *str, char **argv, char ***arge, t_str **env)
{
	if (search_operator(argv, '>') || search_operator(argv, '<'))
		redirection_operators(str, argv, arge, env);
	else
	{
		revert_caracter(argv);
		commands(str, argv, arge, env);
	}
	free_split(argv);
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
	while (i <= n_process)
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
