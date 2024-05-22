/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/05/02 08:44:10 by joseanto         ###   ########.fr       */
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





int	main(int argc, char **argv, char **argenv)
{
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

		quotes(str);
		remove_quotes(str);
		args = ft_split(str, ' ');
		swap_tab(args);
		argument_management(args, &env_list);
		revert_caracter(args);


// int	i = 0;
// while (argenv[i])
// {
// 	printf("%s\n", argenv[i]);
// 	i++;
// }

		if (search_pipe(args))
		{
printf("chegou aki\n");
		}
		else
		{
			commands(str, args, argenv, &env_list);
		}

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
