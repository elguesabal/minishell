#include <stdlib.h>
#include <readline/readline.h>
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = readline("teste: ");	// COMPILAR COM A FLAG -lreadline
	printf("teste: %s\n", str);
	free(str);
	return (0);
}