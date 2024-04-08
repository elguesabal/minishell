#include "../minishell.h"

void	pwd(void)	// PENSAR MELHOR SOBRE OQ ESSA FUNCAO DEVE RETORNAR E COMO TRATAR ERROS
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
		printf("%s\n", pwd);
	else
		printf("Error\npwd nao funcionou\n");
	free(pwd);
}
