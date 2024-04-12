#include "../minishell.h"

void    exec_program(char **argv)
{
	pid_t	pid;
	char	**path;
	char	*env;
	int	i;

(void)argv;

    pid = fork();
    if (pid == -1)
        printf("Error\n a funcao fork() retornou -1\n");
    else if (pid == 0)
    {
        env = getenv("PATH");
        path = ft_split(env, ':');
        // free(env); ESTA DANDO ESSE ERRO munmap_chunk(): invalid pointer


i = 0;
while (path[i])	// LE TODAS AS PATHS
{
    printf("testando: %s\n", path[i]);
    i++;
}


        // i = 0;
        // while (i =! -1 && argv[i])
        // {
        // 	if (path[i])	// FAZER UMA FUNCAO PARA TESTAR O PATH
        // 	{
        // 		if (execve(path[i], argv, NULL) == -1)
        // 			printf("%s: comando não encontrado\n", argv[0]);
        // 		i = -2;
        // 	}
        // 	i++;
        // }



        // free_split(path);
    }
    else if (pid > 0)
    {
        if (waitpid(pid, NULL, 0) == -1)
            printf("Error\n a funcao waitpid() retornou -1\n");
    }
}