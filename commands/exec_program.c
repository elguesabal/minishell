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
/// @return RETORNA UMA COPIA DE file CASO stat(file, &info) == 0
/// @return RETORNA O CAMIHNO ABSOLUTO CONSTRUIDO PELA FUNCAO build_path() CASO A FUNCAO stat() AFIRME Q O CAMINHO E ARQUIVO SAO VALIDOS
/// @return CASO A FUNCAO stat() RETORN -1 EM TODAS AS TENTATIVAS A FUNCAO tester_path() RETORNA UM ENDERECO DE MEMORIA CONTENDO '\0'
char    *tester_path(char **path, char *file)
{
    char    *path_file;
	struct stat info;

	if (stat(file, &info) == 0)
		return (copy_str(file));
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
	struct stat	info;
	int	status;

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

		// if ((stat(argv[0], &info) == -1 || access(argv[0], X_OK) == -1) && execve(argv[0], argv, env) == -1) // TESTA O CAMINHO ABSOLUTO OU RELATIVO ENVIADO NO ARGUMENTO
// 		if (1) // TESTA O CAMINHO ABSOLUTO OU RELATIVO ENVIADO NO ARGUMENTO
// 		{
// 			// AKI NADA DEVE SER FEITO PQ ESTA EXECUTANDO OUTRO PROGRAMA
// (void)info;
// printf("testeeeee: %d\n", stat(argv[0], &info));
// printf("testeeeee: %d\n", access(argv[0], X_OK));
// // if (stat(argv[0], &info) == 0)
// // {
// // printf("caiu aki\n");
// // }
// 		}
// 		else
// 		{
		path = ft_split(getenv("PATH"), ':');
		path_file = tester_path(path, *argv);
		free_split(path);


									// ERROR
// printf("env[0]: %s -> %p\n", env[0], env[0]); --> // env[0]: LESSOPEN=| /usr/bin/lesspipe %s -> 0x4b1b040

// ==5505== Syscall param execve(envp[i]) points to unaddressable byte(s)
// ==5505==    at 0x49A908B: execve (syscall-template.S:120)
// ==5505==    by 0x10C237: exec_program (in /home/jose/programacao/minishell/minishell)
// ==5505==    by 0x109636: main (in /home/jose/programacao/minishell/minishell)
// ==5505==  Address 0x4b1b040 is 0 bytes inside a block of size 32 free'd
// ==5505==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==5505==    by 0x10B4D2: variable_status (in /home/jose/programacao/minishell/minishell)
// ==5505==    by 0x10C43F: exec_program (in /home/jose/programacao/minishell/minishell)
// ==5505==    by 0x109636: main (in /home/jose/programacao/minishell/minishell)
// ==5505==  Block was alloc'd at
// ==5505==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
// ==5505==    by 0x109FEC: copy_str (in /home/jose/programacao/minishell/minishell)
// ==5505==    by 0x10A2A1: creat_list (in /home/jose/programacao/minishell/minishell)
// ==5505==    by 0x1093C9: main (in /home/jose/programacao/minishell/minishell)
									// ERROR
				// QUANDO EU PASSO env AKI ME GERA ESSE ERRO NO VALGRIND (NAO ME PERGUNTA O PQ MAS PARECE Q ESSA VARAIVEL TROCA DE ENDERECO DE MEMORIA SOZINHA) // ENGRACADO Q ELA NAO DA ERRO QUANDO EXECUTO env
								  // |
								  // ↓	// TEMPORARIAMENTE IGNORANDO env[0] // O CULPADO ERA O variable_status()
		if (execve(path_file, argv, env) == -1)
		{ // PRECISA DE UM IF VERIFICANDO execve() RETORNOU -1? CASO ISSO NAO ACONTECESSE NENHUMA LINHA A SEGUIR SERIA EXECUTADA KKKK
			if (path_file[0] != '\0' && access(path_file, X_OK) == -1)
				error_message("-minishell: %s: Permissão negada\n", path_file, 11, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
			else if (stat(path_file, &info) == 0 && S_ISDIR(info.st_mode))
				error_message("-minishell: %s: É um diretório\n", path_file, 12, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
			else if (*argv[0] == '.' && stat(path_file, &info) == -1)
				error_message("-minishell: %s: Arquivo ou diretório inexistente\n", *argv, 13, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
			else if (path_file[0] == '\0' && *argv[0] != '.')
				error_message("%s: comando não encontrado\n", *argv, 14, env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
			else
				printf("nao previ isso kkkkk\n"); // AKI EU VOU PROCURANDO FALHAS
			free(path_file);
			exit_shell(argv, str, env, env_list); // MATAR O PROCESSO PRA NAO DUPLICAR
		}
		// }
		// free(path_file); // SE execve(path_file, argv, env) != -1 ESSA LINHA NUNCA VAI ACONTECER KKKKKK
    }
    else if (pid > 0) // WIFSIGNALED() E WTERMSIG() MACROS PARA SAIDAS DE SINAIS SINAIS
    {
        if (waitpid(pid, &status, 0) == -1)
            printf("Error: a funcao waitpid() retornou -1\n");
		if (WIFEXITED(status))
			variable_status(WEXITSTATUS(status), env_list); // AINDA NAO SEI AO CERTO QUAL STATUS COLOCAR
    }
}
