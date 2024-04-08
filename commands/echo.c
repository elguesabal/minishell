#include "../minishell.h"

void	echo(char *comand)	// PENSAR MELHOR SOBRE OQ ESSA FUNCAO DEVE RETORNAR E COMO TRATAR ERROS
{
	char flag;

	flag = '\n';
	while (*comand && *comand != ' ' && *comand != '	')
		comand++;
	while (*comand && (*comand == ' ' || *comand == '	'))
		comand++;
	if (comand[0] == '-' && comand[1] == 'n')
	{
		flag = '\0';
		comand += 2;
		while (*comand && (*comand == ' ' || *comand == '	'))
			comand++;
	}
	printf("%s%c", comand, flag);
}
