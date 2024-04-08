#include <stdlib.h>
#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

int	cd(char *path)	// EM TESTES AINDA
{
	char	*command;
	char	*pwd;
	int		i;
printf("%s\n", path);

	path += 2;
	while (*path != ' ' && *path != '	')
		path++;

	pwd = getcwd(NULL, 0);

	if (path[0] == '.' && path[1] == '.')
	{
		i = 0;
		while (pwd[i])
			i++;

		while (pwd[i] != '/')
		{
			pwd[i] = '\0';
			i--;
		}
		pwd[i] = '\0';	// pwd[i] == '/';
	}
	else
	{

	}

printf("%s\n", path);
printf("%s\n", pwd);

	// chdir(pwd);
	// // chdir(command);


	// printf("onde estou: %s\n", pwd);

	free(command);
	free(pwd);
	return (0);
}

int	main(int argc, char **argv)
{
	cd(argv[1]);
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
