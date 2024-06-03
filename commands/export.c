#include "../minishell.h"

/// @brief PROCURA UMA ESTRING (VARIAVEL DE AMBIENTE) DENTRO DE UMA LISTA ENCADEADA
/// @param no LISTA A SER PERCORRIDA
/// @param s2 STRING A SER COMPARADA
/// @return RETORNA O NO CASO ENCONTRE A VARIAVEL
/// @return SE NAO ENCONTRAR A VARIAVEL RETORNA NULL
t_str	*search_variable_list(t_str **no, char *str)
{
	t_str	*assist;

	assist = *no;
// printf("str: %s\n", str);
// printf("str: %c\n", assist->str[0]);
	if (str[0] == '?' && str[1] == '\0') // TIVE Q FAZER ESSA GAMBIARRA POR CAUSA DA EXCECAO DA VARIAVEL DE STATUS (?) // NAO FUNCIONOU
	{
		while (assist)
		{
			if (assist->str[0] == '?' && assist->str[1] == '=')
			{
// printf("coringuei: %s\n", assist->str);
				return (assist);
			}
			assist = assist->next;
		}
	}
	while (assist)
	{
		if (compare_variable(assist->str, str))
			return (assist);
		assist = assist->next;
	}
// printf("retornou NULL tbm; str: %s\n", str);
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
	int	i;

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

// printf("env[0][0]: %s\n", env[0][0]);
// printf("env[0][1]: %s\n", env[0][1]);
// printf("env[0][2]: %s\n", env[0][2]);

// printf("env[0]: %p\n", env[0]);
// printf("env: %p\n", env);
// printf("env: %s\n", env[0][0]);
// printf("new_env: %p\n", new_env);

// i = 0;
// while (new_env[i])
// {
// 	printf("new_env[i]: %s\n", new_env[i]);
// 	i++;
// }

	free(*env);
	*env = new_env;	// KARAI ESSA POHA TA ME VENCENDO
	// return (new_env);
// printf("teste: %p\n", env[0]);
}

/// @brief COMPARTILHA O ENDERECO DE MEMORIA CITADO EM **argv Q ESTA ARMAZENADO EM **env_list ASSIM QUANDO OUVER ALGUM SUBPROCESSO SERA PASSADO **env COMO ARGUMENTO
/// @param argv ARGUMENTOS PASSADOS NO readline()
/// @param env PONTEIRO PARA PONTEIRO QUE ESTA COM AS VARIAVEIS DISPONIVEIS PARA SUBPROCESSOS
/// @param env_list LISTA ENCADEADA Q CONTEM TODAS AS VARIAVEIS DE AMBIENTE
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM TODOS AS VARIAVEIS DE AMBIENTE CASO ENCONTRADO A VARIAVEL CITADA EM argv
/// @return RETORNA O ENDERECO DE MEMORIA ANTIGO CASO A VARIAVEL NAO SEJA ENCONTRADA NA LISTA ENCADEADA
void	export(char **argv, char ***env, t_str **env_list) // ESTA FUNCAO NAO RETORNA MAIS NADA E FAZ A MODIFICACAO DIRETO NO ENDERECO DE MEMORIA DO PONTEIRO char **argenv DA MAIN
{
	int	i;
	t_str	*return_env;
	char	*name_variable;
	char	**arg;

	i = 1;
	while (argv[i])
	{
// printf("argv[%d]: %s\n", i, argv[i]);
		if (declaration_variable(argv[i])) // SE TRUE argv[i] == "ARG=VALOR"
		{
			arg = malloc(2 * sizeof(char *)); // ALTERNATIVA PARA A LINHA:  add_variable(&argv[i], *env, env_list); (90)
			if (argv == NULL)
				return ;
			arg[0] = argv[i];
			arg[1] = NULL;
			add_variable(arg, *env, env_list);
			free(arg); // ALTERNATIVA PARA A LINHA: add_variable(&argv[i], *env, env_list); (90)
			// add_variable(&argv[i], *env, env_list); ALTERNATIVA PARA AS LINHAS: arg = malloc(2 * sizeof(char *)); (83) A free(arg); (89)
			name_variable = copy_name_variable(argv[i]);
			free(argv[i]);
			argv[i] = name_variable;
		}
		else if (argv[i] == NULL || (argv[i][0] >= '0' && argv[i][0] <= '9') || metacaracterer(argv[i]))
			error_message("-minishell: export: `%s': não é um identificador válido\n", argv[i], 912, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
		// else
		// 	printf("ja existia mas nao era exportado\n");
// printf("env: %p\n", env);

		return_env = search_variable_list(env_list, argv[i]); // SE declaration_variable() RETORNAR 1 SIGNIFICA Q A STRING TEM O SEU CONTEUDO "=..." E A FUNCAO search_variable_list ESPERA SO O NOME DA VARIAVEL
		if (return_env && !search_variable_array(*env, return_env->str))
			export_variable(env, return_env->str);
// printf("return_env->str: %s\n", return_env->str);
// printf("env: %p\n", env);
		i++;
	}
}
