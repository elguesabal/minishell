#include "../minishell.h"


// PROCURA O ARQUIVOS DO ARGUMENTO *file EM TODOS OS CAMINHOS DO ARGUMENTO **path
// RETORNA O CAMIHNO ABSOLUTO CONSTRUIDO PELA FUNCAO build_path() CASO A FUNCAO stat() AFIRME Q O CAMINHO E ARQUIVO SAO VALIDOS
// CASO A FUNCAO stat() RETORN -1 EM TODAS AS TENTATIVAS A FUNCAO tester_path() RETORNA UM ENDERECO DE MEMORIA CONTENDO '\0'
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

void    exec_program(char **argv, char **env, char *str)
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

		path = ft_split(getenv("PATH"), ':');
		path_file = tester_path(path, *argv);
        free_split(path);

		if (execve(path_file, argv, env) == -1) // O ERRO DESCRITO ACIMA ACONTECIA PQ EU ESTAVA PASSANDO NULL AI A FUNCAO NAO LIDA BEM E OCORRE ACESSO DE MEMORIA INDEVIDO
		{ // PRECISA DE UM IF VERIFICANDO execve() RETORNOU -1? CASO ISSO NAO ACONTECESSE NENHUMA LINHA A SEGUIR SERIA EXECUTADA KKKK
			printf("%s: comando não encontrado\n", argv[0]);
			free(path_file);
			exit_shell(argv, str); // MATAR O PROCESSO PRA NAO DUPLICAR
		}
		// free(path_file); // SE execve(path_file, argv, env) != -1 ESSA LINHA NUNCA VAI ACONTECER KKKKKK
    }
    else if (pid > 0)
    {
        if (waitpid(pid, NULL, 0) == -1)
            printf("Error: a funcao waitpid() retornou -1\n");
    }
}
