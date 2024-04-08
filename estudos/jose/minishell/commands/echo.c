#include "../minishell.h"

void	echo(char *comand)	// PENSAR MELHOR SOBRE OQ ESSA FUNCAO DEVE RETORNAR E COMO TRATAR ERROS
{
	while (*comand && *comand != ' ' && *comand != '	')
		comand++;
	while (*comand && (*comand == ' ' || *comand == '	'))
		comand++;
	printf("%s\n", comand);
}