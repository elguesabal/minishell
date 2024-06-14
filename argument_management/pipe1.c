/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:24 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:11:48 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
