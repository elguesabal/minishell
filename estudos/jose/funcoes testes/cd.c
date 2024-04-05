#include <stdlib.h>
#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

int	cd(char *path)	// EM TESTES AINDA
{
	char	*command;
	char	*pwd;

	chdir(command);

	pwd = getcwd(NULL, 0);

	printf("onde estou: %s\n", pwd);

	free(command);
	free(pwd);
	return (0);
}

int	main(int argc, char **argv)
{
	pwd(argv[1]);
	return (0);
}




// int	main(void)
// {
// 	int		status;
// 	char	buffer[100];

// 	getcwd(buffer, sizeof(buffer));
// 	printf("diretorio atual: %s\n", buffer);

// 	chdir("/nfs/homes/joseanto");
// 	getcwd(buffer, sizeof(buffer));
// 	printf("status: %d\tdiretorio atual: %s\n", status, buffer);

// 	return (0);
// }
