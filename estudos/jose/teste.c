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


	printf("%s\n", getenv("PATH"));

	return (0);
}