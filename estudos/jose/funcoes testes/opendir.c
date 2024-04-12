#include <stdio.h>
#include <dirent.h>

// opendir closedir readdir



// int	main(void)
// {
// 	DIR	*dir;

// 	dir = opendir(".");

// 	if (dir == NULL)
// 		printf("Erro ao abrir diretorio\n");
// 	else
// 		printf("Diretorio aberto\n");

// 	return (0);
// }





// int	main(void)
// {
// 	DIR	*dir;

// 	dir = opendir(".");

// 	if (dir == NULL)
// 		printf("Erro ao abrir diretorio\n");
// 	else
// 		printf("Diretorio aberto\n");

// 	closedir(dir);

// 	return (0);
// }





int	main(void)
{
	DIR				*dir;
	struct dirent	*info;

	dir = opendir(".");

	while ((info = readdir(dir)) != NULL)
		printf("teste: %s\n", info->d_name);

	closedir(dir);
	return (0);
}