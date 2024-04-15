#include "../minishell.h"

void	pwd(void) // FALTA ATUALIZAR A VARIAVEL DE AMBIENTE PWD
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
		printf("%s\n", pwd);
	else
		printf("Error\npwd nao funcionou\n");
	free(pwd);
}
