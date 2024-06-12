#include "../minishell.h"

/// @brief CONCATENA O PRIMEIRO ARGUMENTO COM O SEGUNDO EM UM NOVO ENDERECO DE MEMORIA ADICIONANDO UM '/' NO MEIO
/// @param str1 STRING QUE SERA COPIADA ANTES DA '/'
/// @param str2 STRING QUE SERA COPIADA APOS DA '/'
/// @return RETORNA UM ENDERECO DE MEMORIA CASO PASSADO DUAS ESTRING EXEMPLO: concatenate("ft", "42") == "ft/42"
/// @return RETORNA NULL CASO ALGUM PARAMETRO SEJA NULL OU TENHA ERRO NA FUNCAO malloc() EXEMPLO: concatenate("ft", NULL) == NULL
char	*build_path(char *str1, char *str2)
{
	char	*str;
	int		i;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	str = malloc((ft_strlen(str1) + ft_strlen(str2) + 2) * sizeof(char));
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
/// @return RETORNA UMA COPIA DE file CASO stat(file, &info) == 0
/// @return RETORNA O CAMIHNO ABSOLUTO CONSTRUIDO PELA FUNCAO build_path() CASO A FUNCAO stat() AFIRME Q O CAMINHO E ARQUIVO SAO VALIDOS
/// @return CASO A FUNCAO stat() RETORN -1 EM TODAS AS TENTATIVAS A FUNCAO tester_path() RETORNA UM ENDERECO DE MEMORIA CONTENDO '\0'
char	*tester_path(char **path, char *file)
{
	char		*path_file;
	struct stat info;

	if (stat(file, &info) == 0)
		return (copy_str(file));
	while (path && *path)
	{
		path_file = build_path(*path, file);
		if (stat(path_file, &info) == 0)
			return (path_file);
		free(path_file);
		path++;
	}
	path_file = malloc(sizeof(char));
	*path_file = '\0';
	return (path_file);
}

/// @brief GERENCIA ERRO CASO A FUNCAO execve() NAO FUNCIONA 
/// @param path_file CAMINHO PASSADO COMO PRIMEIRO ARGUMENTO PARA execve()
/// @param env_list LISTA ENCADEAD COM TODAS AS VARIAVEIS DE AMBIENTE
/// @param argv ARGUMENTOS PASSADO PARA O PROCESSO QUE FALHOU
void	error_execve(char *path_file, t_str **env_list, char **argv)
{
	struct stat	info;

	if (path_file[0] != '\0' && access(path_file, X_OK) == -1)
		error_message("-minishell: %s: Permissão negada\n", path_file, 11, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
	else if (stat(path_file, &info) == 0 && S_ISDIR(info.st_mode))
		error_message("-minishell: %s: É um diretório\n", path_file, 12, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
	else if (*argv[0] == '.' && stat(path_file, &info) == -1)
		error_message("-minishell: %s: Arquivo ou diretório inexistente\n", *argv, 13, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
	else if (path_file[0] == '\0' && *argv[0] != '.')
		error_message("%s: comando não encontrado\n", *argv, 14, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
	free(path_file);
}

void	exec_program(char **argv, char **env, char *str, t_str **env_list)
{
	pid_t	pid;
	t_str	*variable;
	char	**path;
	char	*path_file;
	int		status;

	path = NULL;
	pid = fork();
	if (pid == 0)
	{
		variable = search_variable_list(env_list, "PATH");
		if (variable)
			path = ft_split(&variable->str[5], ':');
		path_file = tester_path(path, *argv);
		if (path)
			free_split(path);
		execve(path_file, argv, env);
		error_execve(path_file, env_list, argv);
		exit_shell(argv, str, env, env_list);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		variable_status(WEXITSTATUS(status), env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
}
