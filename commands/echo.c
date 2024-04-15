#include "../minishell.h"


// PROCURA UMA STRING DE ATE 2 ELEMENTOS DENTRO DE OUTRA STRING SEM CONSIDERAR OQ TEM EM TORNO DA STRING PROCURADA
// RETORNA 1 CASO ENCONTRE A STRING EXEMPLO: "echo teste >> teste.txt", ">>" OU "echo teste>teste.txt", ">"
// RETORNA 0 CASO NAO ENCONTRE A STRING EXEMPLO: "echo teste > teste.txt", ">>"
// int	search_operator(char *str, char *operator)
// {
// 	while (*str)
// 	{
// 		if (*str == operator[0])
// 		{
// 			if (operator[1] == '\0')
// 				return (1);
// 			else if (operator[1] == str[1])
// 				return (1);
// 		}
// 		str++;
// 	}
// 	return (0);
// }


// PROCURA UMA STRING NAS POSICOES INICIAIS DE ATE 2 ELEMENTOS DENTRO DE CADA STRING DENTRO DE ARRAY DE STRINGS
// RETORNA 1 CASO ENCONTRE A STRING EXEMPLO: {"echo" "teste" ">>" "teste.txt"}, ">>"
// RETORNA 0 CASO NAO ENCONTRE A STRING EXEMPLO: {"echo" "teste" ">" "teste.txt"}, ">>" OU {"echo" "teste>teste.txt"}, ">"
// int	search_operator(char **argv, char *operator)
// {
// 	while (*argv)
// 	{
// 		if ((*argv)[0] == operator[0] && (*argv)[1] == operator[1])
// 			return (1);
// 		argv++;
// 	}
// 	return (0);
// }


void	echo(char **argv)
{
	char	flag;
	int	i;

	flag = '\n';
	i = 1;
	if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'n')
	{
		flag = '\0';
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	printf("%c", flag);
}
