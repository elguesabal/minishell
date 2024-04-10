#include "../minishell.h"



// PROCURA UMA STRING DE ATE 2 ELEMENTOS DENTRO DE OUTRA STRING SEM CONSIDERAR OQ TEM EM TORNO DA STRING PROCURADA
// RETORNA 1 CASO ENCONTRE A STRING EXEMPLO: "echo teste >> teste.txt", ">>" OU "echo teste>teste.txt", ">"
// RETORNA 0 CASO NAO ENCONTRE A STRING EXEMPLO: "echo teste > teste.txt", ">>"
int	search_operator(char *str, char *operator)
{
	while (*str)
	{
		if (*str == operator[0])
		{
			if (operator[1] == '\0')
				return (1);
			else if (operator[1] == str[1])
				return (1);
		}
		str++;
	}
	return (0);
}



void	echo(char **argv)	// AINDA TESTANDO ALGUMAS COISAS ENTAO IGNORAR POR ENQUANTO ESSA FUNCAO
{
	char	flag;
	int	output;
	int	fd;
	int	new_stdout;

	flag = '\n';
	output = 1;
	// new_stdout = 1;	// TALVEZ EU DEVA INICIAR COM 1 PRA DEIXAR A FUNCAO dup2 FORA DE IF

	// command = skip_char(command);
	// command = skip_space(command);
	// if (command[0] == '-' && command[1] == 'n')
	// {
		// command = skip_char(command);
		// command = skip_space(command);
	// }


	if (argv[1][0] == '-' && argv[1][1] == 'n')
	{
		flag = '\0';
		output++;
	}


	if (compare(">>", argv[output + 1]))	// >>	// DEVO FAZER ISSO FORA DA FUNCAO
	{
		fd = open(argv[output + 2], O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
		new_stdout = dup(STDOUT_FILENO);
		dup2(fd, STDOUT_FILENO);
	}
	else if (compare(">", argv[output + 1]))	// >
	{}
	else if (0)	// <
	{}
	else if (0)	// <<
	{}
	// else
	// 	printf("%s%c", command, flag);



	printf("%s%c", argv[output], flag);


	dup2(new_stdout, STDOUT_FILENO);
	// NAO USEI A FUNCAO close PARA FECAR NENHUM open
}
