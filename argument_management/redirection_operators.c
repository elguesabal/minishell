#include "../minishell.h"

/// @brief RECEBE OS ARGUMENTOS E CONTA ATE O PROXIMO OPERADOR DE REDIRECIONAMENTO
/// @param argv ARRAY COM TODOS ARGUMENTOS
/// @return RETORNA O TAMANHO DOS ARGUMENTOS ATE O PROXIMO OPERADOR DE REDIRECIONAMENTO
int	len_arguments(char **argv)
{
	int	len;

	len = 0;
	while (argv[len] && argv[len][0] != '|' && argv[len][0] != '>' && argv[len][0] != '<')
		len++;
	return (len);
}

/// @brief RECEBE OS ARGUMENTOS ALLOCA MEMORIA CORRETAMENTE E COPIA OS ARGUMENTOS ANTES DO PRIMEIRO OPERADOR DE REDIRECIONAMENTO ENCONTRADO
/// @param argv ARRAY COM TODOS ARGUMENTOS
/// @return RETORNA UMA COPIA DOS ARGUMENTOS DO COMANDO ATE ENCONTRAR UM OPERADOR DE REDIRECIONAMENTO
char	**next_process(char **argv)
{
	char	**args_process;
	int	i;

	args_process = malloc((len_arguments(argv) + 1) * sizeof(char *));
	if (args_process == NULL)
		return (NULL);
	i = 0;
	while (argv[i] && argv[i][0] != '|' && argv[i][0] != '>' && argv[i][0] != '<')
	{
		args_process[i] = copy_str(argv[i]);
		i++;
	}
	args_process[i] = NULL;
	return (args_process);
}

/// @brief INICIALIZA O PROCESSO DE REDIRECIONAMENTO DA FUNCAO redirection_operators()
/// @param argv ARRAY COM TODOS ARGUMENTOS
/// @param process POSICAO DO ARGUMENTO ATUAL
/// @param operator IDENTIFICADOR DO PROXIMO OPERADOR
/// @param env_list LISTA ENCADEADA COM TODAS AS VARIAVEIS DE AMBIENTE
/// @return RETORNA UMA COPIA DOS ARGUMENTOS DO COMANDO ATE ENCONTRAR UM OPERADOR DE REDIRECIONAMENTO
char	**init_redirection(char **argv, int *process, int *operator, t_str **env_list)
{
	char	**args_process;

	args_process = next_process(&argv[*process]);
	while (argv[*process + 1] && argv[*process][0] != '|')
	{
		*operator = search_next_operator(&argv[*process]);
		if (*operator == 2)
			init_bigger_then(&argv[*process]);
		else if (*operator == 3)
			init_bigger_bigger_than(&argv[*process]);
		else if (*operator == 4)
			init_less_than(&argv[*process]);
		else if (*operator == 5)
			init_smaller_smaller_than(&argv[*process], env_list);
		while (argv[*process + 1] && argv[*process][0] != '|' && argv[*process][0] != '>' && argv[*process][0] != '<')
			(*process)++;
		(*process)++;
	}
	revert_caracter(args_process);
	return (args_process);
}

/// @brief TERMINA O REDIRECIONAMENTO DE redirection_operators()
/// @param argv ARRAY COM TODOS ARGUMENTOS
/// @param new_std COPIAS (DUPLICACOES) SALVAS DE STDIN_FILENO E STDOUT_FILENO ANTES DE QUALQUER REDIRECIONAMENTO
void	finish_redirection(int operator, int *new_std, char **args_process)
{
	if (operator == 2 || operator == 3 || operator == 4 || operator == 5)
	{
		dup2(new_std[0], STDIN_FILENO);
		dup2(new_std[1], STDOUT_FILENO);
		unlink(".heredoc");
	}
	free_split(args_process);
}

void	redirection_operators(char *str, char **argv, char ***argenv, t_str **env_list)
{
	int	process;
	int	operator;
	char	**args_process;
	int	new_std[2];

	new_std[0] = dup(STDIN_FILENO);
	new_std[1] = dup(STDOUT_FILENO);
	process = 0;
	while (argv[process])
	{
		args_process = init_redirection(argv, &process, &operator, env_list);
		if (operator == 2 || operator == 3 || operator == 4 || operator == 5)
			commands(str, args_process, argenv, env_list);
		finish_redirection(operator, new_std, args_process);
		while (argv[process + 1])
			process++;
		process++;
	}
	close(new_std[0]);
	close(new_std[1]);
}
