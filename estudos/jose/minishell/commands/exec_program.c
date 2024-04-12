#include "../minishell.h"

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
    return (NULL);
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
		if (execve(path_file, argv, env) == -1) // AO ESCREVER UM COMANDO INEXISTENTE APRESENTA ESSE ERRO: Syscall param execve(filename) points to unaddressable byte(s)
		{
			printf("%s: comando não encontrado\n", argv[0]);
	        free_split(path);
			free(path_file);
			exit_shell(argv, str); // MATAR O PROCESSO PRA NAO DUPLICAR
		}
        free_split(path);
		free(path_file);
    }
    else if (pid > 0)
    {
        if (waitpid(pid, NULL, 0) == -1)
            printf("Error: a funcao waitpid() retornou -1\n");
    }
}
