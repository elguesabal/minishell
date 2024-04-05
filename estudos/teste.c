#include <stdlib.h>
#include <readline/readline.h>

int	main(void)
{
	char	*command;

	command = readline("minishell: ");

	

	free(command);
	return (0);
}