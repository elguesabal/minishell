#include "../minishell.h"

int	search_redirection(char *str, char c)	// PROCURA UM CARACTER ATE ENCONTRAR OU CHEGAR NO FIM DA STRING
{
	while (*str)
	{
		if (*str == c)
		{
			if (str[1] == c)
				return (1);
			// else if (str[1] != ' ' || str[1] != '	')	// TRATA ALGUM TIPO DE ERRO COMO >| OU <> OU ><
			// 	return (-1);
		}
		str++;
	}
	return (0);
}

void	echo(char *command)
{
	char flag;

	flag = '\n';
	command = skip_char(command);
	command = skip_space(command);
	if (command[0] == '-' && command[1] == 'n')
	{
		flag = '\0';
		command = skip_char(command);
		command = skip_space(command);
	}
	if (search_redirection(command, '>'))
	{
		while ()	// TERMINAR ISSO EM CASA
			w
	}
	else
		printf("%s%c", command, flag);
}
