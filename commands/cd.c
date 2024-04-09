#include "../minishell.h"

void    cd(char *command)
{
	command = skip_char(command);
	command = skip_space(command);
	if (chdir(command) == -1)
		printf("minishell: cd: %s: Arquivo ou diretório inexistente\n", command);
}
