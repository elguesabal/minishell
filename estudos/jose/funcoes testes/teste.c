#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	// int	i = 0;

	// while (argv[i])
	// {
	// 	printf("%s\n", argv[i]);
	// 	i++;
	// }

	// i++;

	// while (argv[i])
	// {
	// 	printf("%s\n", argv[i]);
	// 	i++;
	// }

	// i = 0;
	// while (env[i])
	// {
	// 	printf("%s\n", env[i]);
	// 	i++;
	// }


	// printf("%s\n", getenv("PATH"));


	char	*teste;


	teste = malloc(5 * sizeof(char));
printf("%p\n", teste);
printf("%s\n", teste);
	free(teste);

printf("%p\n", teste);
printf("%s\n", teste);
	return (0);
}