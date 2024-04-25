#include "../minishell.h"

/// @brief PROCURA UMA ESTRING (VARIAVEL DE AMBIENTE) DENTRO DE UMA LISTA ENCADEADA
/// @param no LISTA A SER PERCORRIDA
/// @param s2 STRING A SER COMPARADA
/// @return RETORNA A STRING CASO ENCONTRE A VARIAVEL
/// @return SE NAO ENCONTRAR A VARIAVEL RETORNA NULL
char	*search_variable_list(t_str **no, char *str)
{
	t_str	*assist;

	assist = *no;
	while (assist)
	{
		if (compare_variable(assist->str, str))
			return (assist->str);
		assist = assist->next;
	}
	return (NULL);
}

/// @brief CRIA UM NOVO PONTEIRO PARA PONTEIRO REUTILIZANDO AS ANTIGAS STRINGS E ADICIONANDO UMA NOVA AO FINAL
/// @param env ARRAY COM TODAS AS VARIAVEIS DE AMBIENTE MENO A NOVA
/// @param str NOVA VARIAVEL DE AMBIENTE A SER INCLUIDA EM env
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM TODOS AS VARIAVEIS DE AMBIENTE
char	**export_variable(char **env, char *str)
{
	char	**new_env;
	int	i;

	new_env = malloc((strstrlen(env) + 2) * sizeof(char *));
	if (!new_env)
	{
		printf("Error\na funcao malloc() retornou NULL\n");
		return (env);
	}
	i = 0;
	while (env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	free(env);
	new_env[i] = str;
	new_env[i + 1] = NULL;
	return (new_env);
}

/// @brief COMPARTILHA O ENDERECO DE MEMORIA CITADO EM **argv Q ESTA ARMAZENADO EM **env_list ASSIM QUANDO OUVER ALGUM SUBPROCESSO SERA PASSADO **env COMO ARGUMENTO
/// @param argv ARGUMENTOS PASSADOS NO readline()
/// @param env PONTEIRO PARA PONTEIRO QUE ESTA COM AS VARIAVEIS DISPONIVEIS PARA SUBPROCESSOS
/// @param env_list LISTA ENCADEADA Q CONTEM TODAS AS VARIAVEIS DE AMBIENTE
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM TODOS AS VARIAVEIS DE AMBIENTE CASO ENCONTRADO A VARIAVEL CITADA EM argv
/// @return RETORNA O ENDERECO DE MEMORIA ANTIGO CASO A VARIAVEL NAO SEJA ENCONTRADA NA LISTA ENCADEADA
char	**export(char **argv, char **env, t_str **env_list)
{
	int	i;
	char	*return_env;

	i = 1;
	while (argv[i])
	{
		return_env = search_variable_list(env_list, argv[i]);
		if (return_env)
			env = export_variable(env, return_env); // EXPORTA TODAS AS VARIAVEIS ENCONTRADAS NOS ARGUMENTOS
			// return (export_variable(env, return_env)); // SO EXPORTA A PRIMEIRA VARIAVEL ENCONTRADA
		i++;
	}
	return (env);
}
