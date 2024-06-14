/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:51 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief DECLARA E EXPORTA UMA VARIAVEL DE AMBIENTE
/// @param i INDICE QUE argv DEVE SER ACESSADO
/// @param argv ARGUMENTOS PASSADO COMO COMANDO
/// @param env ARRAY COM VARIAVEIS DE AMBIENTE EXPORTADAS
/// @param env_list LISTA ENCADEADA COM TODAS AS VARIAVEIS DE AMBIENTE
void	declaration_and_export(int i, char ***argv, char ***env, t_str **env_list)
{
	char	**arg;
	char	*name_variable;

	arg = malloc(2 * sizeof(char *));
	if (*argv == NULL)
		return ;
	arg[0] = argv[0][i];
	arg[1] = NULL;
	add_variable(arg, *env, env_list);
	free(arg);
	name_variable = copy_name_variable(argv[0][i]);
	free(argv[0][i]);
	argv[0][i] = name_variable;
}

/// @brief PROCURA UMA ESTRING (VARIAVEL DE AMBIENTE) DENTRO DE UMA LISTA ENCADEADA
/// @param no LISTA A SER PERCORRIDA
/// @param s2 STRING A SER COMPARADA
/// @return RETORNA O NO CASO ENCONTRE A VARIAVEL
/// @return SE NAO ENCONTRAR A VARIAVEL RETORNA NULL
t_str	*search_variable_list(t_str **no, char *str)
{
	t_str	*assist;

	assist = *no;
	if (str[0] == '?' && str[1] == '\0')
	{
		while (assist)
		{
			if (assist->str[0] == '?' && assist->str[1] == '=')
				return (assist);
			assist = assist->next;
		}
	}
	while (assist)
	{
		if (compare_variable(assist->str, str))
			return (assist);
		assist = assist->next;
	}
	return (NULL);
}

/// @brief PROCURA UMA ESTRING (VARIAVEL DE AMBIENTE) DENTRO DE UM ARRAY
/// @param env ARRAY A SER PROCURADO
/// @param str STRING A SER COMPARADA
/// @return RETORNA 0 CASO ENCONTRE A VARIAVEL
/// @return RETORNA 1 CASO NAO ENCONTRAR A VARIAVEL
int	search_variable_array(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == str)
			return (1);
		i++;
	}
	return (0);
}

/// @brief CRIA UM NOVO PONTEIRO PARA PONTEIRO REUTILIZANDO AS ANTIGAS STRINGS E ADICIONANDO UMA NOVA AO FINAL
/// @param env ARRAY COM TODAS AS VARIAVEIS DE AMBIENTE MENO A NOVA
/// @param str NOVA VARIAVEL DE AMBIENTE A SER INCLUIDA EM env
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM TODOS AS VARIAVEIS DE AMBIENTE
void	export_variable(char ***env, char *str) // ESTA FUNCAO NAO RETORNA MAIS NADA E FAZ A MODIFICACAO DIRETO NO ENDERECO DE MEMORIA DO PONTEIRO char **argenv DA MAIN
{
	char	**new_env;
	int		i;

	new_env = malloc((strstrlen(*env) + 2) * sizeof(char *));
	if (new_env == NULL)
		return ;
	i = 0;
	while (env[0][i])
	{
		new_env[i] = env[0][i];
		i++;
	}
	new_env[i] = str;
	new_env[i + 1] = NULL;
	free(*env);
	*env = new_env;
}

/// @brief COMPARTILHA O ENDERECO DE MEMORIA CITADO EM **argv Q ESTA ARMAZENADO EM **env_list ASSIM QUANDO OUVER ALGUM SUBPROCESSO SERA PASSADO **env COMO ARGUMENTO
/// @param argv ARGUMENTOS PASSADOS NO readline()
/// @param env PONTEIRO PARA PONTEIRO QUE ESTA COM AS VARIAVEIS DISPONIVEIS PARA SUBPROCESSOS
/// @param env_list LISTA ENCADEADA Q CONTEM TODAS AS VARIAVEIS DE AMBIENTE
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM TODOS AS VARIAVEIS DE AMBIENTE CASO ENCONTRADO A VARIAVEL CITADA EM argv
/// @return RETORNA O ENDERECO DE MEMORIA ANTIGO CASO A VARIAVEL NAO SEJA ENCONTRADA NA LISTA ENCADEADA
void	export(char **argv, char ***env, t_str **env_list)
{
	int		i;
	t_str	*return_env;

	variable_status(0, env_list);
	i = 1;
	while (argv[i])
	{
		if (declaration_variable(argv[i]))
			declaration_and_export(i, &argv, env, env_list);
		else if (argv[i] == NULL || (argv[i][0] >= '0' && argv[i][0] <= '9')
			|| metacaracterer(argv[i]))
			error_message(
				"-minishell: export: `%s': não é um identificador válido\n",
				argv[i], 1, env_list);
		return_env = search_variable_list(env_list, argv[i]);
		if (return_env && !search_variable_array(*env, return_env->str))
			export_variable(env, return_env->str);
		i++;
	}
}
