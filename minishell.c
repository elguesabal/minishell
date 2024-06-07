/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/04 19:16:25 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// 				IDEAIA DE COMO FAZER INTERPRETACAO DE ASPAS (NAO INTERPRETAR METACARACTERES DENTRO DAS ASPAS)

// a tabela ascii vai de 0 a 127, alguns caracteres talvez nao tenham possibilidade de uso em um shell, dito isso, talvez possa usar alguns desses
// para nao interpretar propositalmente os metacaracteres (tbm estou verificando a possibildade de utrapassar os valores de 0 a 127 do UTF-8)

// se caso definirmos um "codigo" para cada metacaracterer, poderiamos substitui-los antes de ser interpretado por nossa minishell
// EXEMPLO: imagine que eu troque o $ por 500 ($ na tabela ascii vale 36)

// int caracter = '$'; /* OU */ int caracter = 36;

// printf("%c", caracter); // PRINT: $
// caracter = 500;
// printf("%c", caracter); // PRINT: �

// ou seja, uma variavel do tipo char pode assumir um caracter alem da tabela ascii, sendo assim eu poderia definir um consenso:
// $ -> 500
// > -> 501
// >> -> nada pq seria a juncao de char string[3] = { 501, 501, NULL };
// | -> 502
// < -> 503
// << nada pq seria a juncao de char string[3] = { 503, 503, NULL };

// se fizer uma substituicao dos metacaracteres por valores inexistente a funcao argument_management() nao vai identificar algo a ser feito
// dps de passado por essa funcao so retornar ao estado original e limpar com a funcao ft_trim()



void check_operator(char **arg)
{
    int i;

i = 0;
while (arg[i] && arg[i + 1] != NULL)
{
	if (arg[i][0] == '|')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '>')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '<')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	i++;
}
	if (arg[i][0] == '|' && (arg[i][1] == '>' || arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '>' && (arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '<' && (arg[i][1] == '|' || arg[i][1] == '>'))
		printf("syntax error near '%c'\n", arg[i][0]);
}


int	main(int argc, char **argv, char **argenv)
{
// printf("main getpid(): %d\n", getpid());
	char	*str;
	char	**args;
	t_str	*env_list;

	(void)argc;
	(void)argv;

	env_list = NULL;
	creat_list(&env_list, argenv);
	argenv = array_to_list(&env_list);
	insert_last(&env_list, copy_str("?=0"));


	while (1)
	{
		str = readline("minishell: "); // printf("teste :%d\n", (*str == '\0')); // CASO PRESSIONE ENTER SEM DIGITAR NADA NO SHELL *str == 0
// printf("testando ctrl+d\n");
		add_history(str);
		quotes(str);
		remove_quotes(str);
		separate_redirection_operators(&str);
		args = ft_split(str, ' ');
		swap_tab(args);
		argument_management(&args, &env_list);

// int	i = 0;
// while (args[i])
// {
// 	printf("%s\n", args[i]);
// 	i++;
// }
// printf("fim do teste\n\n");

		if (search_operator(args, '|'))
		{
			command_pipe(str, args, &argenv, &env_list);
		}
		else if (search_operator(args, '>') || search_operator(args, '<')) // AKI EU DEVERIA SEPARAR ENTRE REDIRECIONADORES PARA ARQUIVO E PROGRAMAS (AI EU PODERIA USAR redirection_operators() DENTRO DE command_pipe())
		{
			redirection_operators(str, args, &argenv, &env_list);
		}
		else
		{
			revert_caracter(args);
			commands(str, args, &argenv, &env_list);
		}

		// revert_caracter(args); // FOI DESTRIBUIDO PARA MOMENTOS ESPECIFICOS QUE SERA OU NAO INTERPRETADO OS METACARACTERES


// i = 0;
// while (args[i])
// {
// 	printf("%s\n", args[i]);
// 	i++;
// }
// printf("fim do teste\n\n");

// int	i = 0;
// while (argenv[i])
// {
// 	printf("%s\n", argenv[i]);
// 	i++;
// }


// 		if (search_operator(args, '|') || search_operator(args, '>') || search_operator(args, '<'))	// FOI JUNTADO COM O IF IDENTICO A ESSE ACIMA
// 		{
// // printf("chegou aki\n");
// 		}
// 		else
// 		{
// 			commands(str, args, &argenv, &env_list);
// 		}

		free(str);
		free_split(args);

	}
	// return (0); // SE O PROGRAMA SAI TERMINA SEMPRE COM A FUNCAO exit() E NECESSARIO O RETURN?
}












// EU IMPLEMENTEI O REDIRECIONAMENTO DE SAIDA NO echo ENTAO ATE EU FIZER ISSO FORA DO echo DEIXAREI ISSO COMENTADO PRA USAR DPS
// void	echo(char **argv)	// AINDA TESTANDO ALGUMAS COISAS ENTAO IGNORAR POR ENQUANTO ESSA FUNCAO
// {
// // printf("teste: %d\n", search_operator(argv, ">>"));


// 	char	flag;
// 	int	output;
// 	int	fd;
// 	int	new_stdout;

// 	flag = '\n';
// 	output = 1;
// 	// fd = ?? // TALVEZ EU DEVA INICIAR O fd PARA USAR close EM QUALQUER SITUACAO
// 	new_stdout = 1;	// TALVEZ EU DEVA INICIAR COM 1 PRA USAR A FUNCAO dup2 EM QUALQUER SITUACAO

// 	if (argv[1][0] == '-' && argv[1][1] == 'n')
// 	{
// 		flag = '\0';
// 		output++;
// 	}

// 	if (search_operator(argv, ">>"))	// >>	// DEVO FAZER ISSO FORA DA FUNCAO
// 	{
// 		fd = open(argv[output + 2], O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
// 		new_stdout = dup(STDOUT_FILENO);
// 		dup2(fd, STDOUT_FILENO);
// 	}
// 	else if (search_operator(argv, ">"))	// >
// 	{}
// 	else if (0)	// <
// 	{}
// 	else if (0)	// <<
// 	{}
// 	// else
// 	// 	printf("%s%c", command, flag);



// 	printf("%s%c", argv[output], flag);


// 	// printf("teste com dup2: %d\n", dup2(new_stdout, STDOUT_FILENO));
// 	dup2(new_stdout, STDOUT_FILENO);
// 	// NAO USEI A FUNCAO close PARA FECAR NENHUM open
// }
