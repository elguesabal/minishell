#include "../minishell.h"

/// @brief CONCATENA O PRIMEIRO ARGUMENTO COM O SEGUNDO EM UM NOVO ENDERECO DE MEMORIA ADICIONANDO UM '/' NO MEIO
/// @param str1 STRING QUE SERA COPIADA ANTES DA '/'
/// @param str2 STRING QUE SERA COPIADA APOS DA '/'
/// @return RETORNA UM ENDERECO DE MEMORIA CASO PASSADO DUAS ESTRING EXEMPLO: concatenate("ft", "42") == "ft/42"
/// @return RETORNA NULL CASO ALGUM PARAMETRO SEJA NULL OU TENHA ERRO NA FUNCAO malloc() EXEMPLO: concatenate("ft", NULL) == NULL
char    *build_path(char *str1, char *str2)
{
    char    *str;
	int	i;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    str = malloc((ft_strlen(str1) + ft_strlen(str2) + 2) * sizeof(char));
	if (str == NULL)
	{
		printf("Error: a funcao malloc() retornou NULL\n");
		return (NULL);
	}
	i = 0;
	while (*str1)
	{
		str[i] = *str1;
		i++;
		str1++;
	}
	str[i] = '/';
	i++;
	while (*str2)
	{
		str[i] = *str2;
		i++;
		str2++;
	}
	str[i] = '\0';
    return (str);
}

/// @brief PROCURA O ARQUIVOS DO ARGUMENTO *file EM TODOS OS CAMINHOS DO ARGUMENTO **path
/// @param path CAMINHOS A SEREM TESTADOS
/// @param file AQUIVO A SER PROCURADO DENTRO DOS CAMINHOS
/// @return RETORNA O CAMIHNO ABSOLUTO CONSTRUIDO PELA FUNCAO build_path() CASO A FUNCAO stat() AFIRME Q O CAMINHO E ARQUIVO SAO VALIDOS
/// @return CASO A FUNCAO stat() RETORN -1 EM TODAS AS TENTATIVAS A FUNCAO tester_path() RETORNA UM ENDERECO DE MEMORIA CONTENDO '\0'
char    *tester_path(char **path, char *file)
{
    char    *path_file;
	struct stat info;

	while (*path)
	{
		path_file = build_path(*path, file);
	    if (stat(path_file, &info) == -1)
		{
			// SE ENTROU AKI E PQ NAO EXISTE AQUELE CAMINHO OU ARQUIVO
            // printf("Error: a funcao stat() retornou -1\n");
		}
        else
			return (path_file);
        free(path_file);
        path++;
    }
	path_file = malloc(sizeof(char));
	*path_file = '\0';
    return (path_file);
}

void    exec_program(char **argv, char **env, char *str, t_str **env_list)
{
	pid_t	pid;
	char	**path;
	// char	*env_path; // EU USAVA ESSA VARIAVEL PRA RECEBER A VARIAVEL PATH
    char    *path_file;

    pid = fork();
    if (pid == -1)
        printf("Error: a funcao fork() retornou -1\n");
    else if (pid == 0)
    {
// env_path = getenv("PATH"); // A FUNCAO getenv() FAZ A VAGABUNDAGEM DE REUTILIZAR O ENDERECO DE MEMORIA DO char **env ALOCADA PELO MAIN POR ISSO O FREE DA ERRO
// printf("env[20]: %p\n", &env[20][5]);
// printf("env_path: %p\n", env_path);
// path = ft_split(env_path, ':');
// free(env_path); // ESTA DANDO ESSE ERRO munmap_chunk(): invalid pointer // O ERRO ACONTECE PQ EU TENTO DESALOCAR MEMORIA Q NAO FOI ALOCADA POR MIM

		if (execve(argv[0], argv, env) == 0) // TESTA O CAMINHO ABSOLUTO OU RELATIVO ENVIADO NO ARGUMENTO
		{
			// AKI NADA DEVE SER FEITO PQ ESTA EXECUTANDO OUTRO PROGRAMA
		}
		else
		{
			path = ft_split(getenv("PATH"), ':');
			path_file = tester_path(path, *argv);
			free_split(path);

			if (execve(path_file, argv, env) == -1) // O ERRO DESCRITO ACIMA ACONTECIA PQ EU ESTAVA PASSANDO NULL AI A FUNCAO NAO LIDA BEM E OCORRE ACESSO DE MEMORIA INDEVIDO
			{ // PRECISA DE UM IF VERIFICANDO execve() RETORNOU -1? CASO ISSO NAO ACONTECESSE NENHUMA LINHA A SEGUIR SERIA EXECUTADA KKKK
				printf("%s: comando não encontrado\n", argv[0]);
				free(path_file);
				exit_shell(argv, str, env, env_list); // MATAR O PROCESSO PRA NAO DUPLICAR
			}
		}
		// free(path_file); // SE execve(path_file, argv, env) != -1 ESSA LINHA NUNCA VAI ACONTECER KKKKKK
    }
    else if (pid > 0)
    {
        if (waitpid(pid, NULL, 0) == -1)
            printf("Error: a funcao waitpid() retornou -1\n");
    }
}
