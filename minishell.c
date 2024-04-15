/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/04/09 14:49:27 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/// @brief PROCURA UMA ESTRING NO COMECO DE OUTRA LEVANADO EM CONSIDERACAO O FINAL DA COMPARACAO
/// @param s1 STRING A SER COMPARADA
/// @param s2 STRING A SER COMPARADA
/// @return SE AO FINAL DA COMPARACAO TENHA ' ' '	' OU '\0' RETORNA 1 EXEMPLO: "ls", "ls -all" ou "pwd", "pwd"
/// @return CASO NO FINAL DA COMPARACAO TENHA ALGO DIFERENTE RETORNA 0 EXEMPLO: "ls", "ls-all" ou "pwd", "pwdx"
int	compare(char *s1, char *s2)	// TRANSFERIR PARA PASTA assistant
{
	int			i;

	if (s2 == NULL)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && s2[i] != ' ' && s2[i] != '	')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}




void	init_count(t_token *info)
{
	info->command = 0;
	// info->arguments = 0;
	info->dollar_sign = 0;
	info->single_quotes = 0;
	info->double_quotes = 0;
	info->bigger_then = 0;
	info->two_greater_than = 0;
	info->pipe = 0;
}


/// @brief PROCURA SE A O SIMBULO $ Q INIDICA VARIAVEL DE AMBIENTE
/// @param str STRING QUE IRAR PROCURAR $
/// @return RETORNA 1 SE OUVER $ E ALGO APOS ISSO EXEMPLO: "teste$PATH"
/// @return RETORNA 0 SE NAO OUVER $ OU SE NAO OUVER MAIS NADA APOS $ EXEMPLO: "teste" OU "teste$"
int	search_dollar_sign(char *str)
{
	while (*str)
	{
		if (*str == '$' && str[1])
			return (1);
		str++;
	}
	return (0);
}


/// @brief USA A FUNCAO free() NO ANTIGO ENDERO E RETONA UM NOVO ENDERECO COM A COPIA DO SEGUNDO ARGUMENTO
/// @param str STRING Q VAI TER A MEMORIA LIBERADA
/// @param new_str UMA STRING Q VAI SER COPIADA NA NOVA MEMORIA ALOCADA (UTIL PRA QUANDO QUERO UM COPIAR INFORMACOES DE VARIAVEIS DE AMBIENTE E NAO ME PREOCUPAR COM FREE NO SPLIT)
/// @return ENDERO COM A COPIA DE new_str
char	*expand_variable(char *str, char *new_str)
{
	int	i;
	char	*copy_new;

	if (new_str == NULL)
	{
		copy_new = malloc(sizeof(char)); // NAO VERIFICADO
		copy_new = '\0';
		return (copy_new);
	}
// printf("aaa: %s, %ld\n", str, (strlen_char(str, '$') + ft_strlen(new_str) + 1)); // echo $PATH -> aaa: $PATH
	copy_new = malloc((strlen_char(str, '$') + ft_strlen(new_str) + 1) * sizeof(char));
	if (copy_new == NULL)
	{
		printf("Error: a funcao malloc() retornou NULL\n");
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '$')
	{
		copy_new[i] = str[i];
		i++;
	}
	free(str);
	while (new_str[i])
	{
		copy_new[i] = *new_str;
		new_str++;
		i++;
	}
	copy_new[i] = '\0';
	return (copy_new);
}

void	analyze(char **argv, t_token *info)
{
	int	i;

	i = 1; // TEM Q COMECAR A VERIFICAR APARTIR DO SEGUNDO ARGUMENTO PQ O PRIMEIRO E O COMANDO
	while (argv[i])
	{
		if (search_dollar_sign(argv[i])) // TENHO QUE VERIFICAR NAO SO NO COMECO DA STRING MAS NO MEIO TBM
		{
			info->dollar_sign++;
			argv[i] = expand_variable(argv[i], getenv(&argv[i][strlen_char(argv[i], '$') + 1]));
// printf("string trocada: %s\n", argv[i]);
		}


		i++;
	}
}


int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**args;
	t_token	info;

	(void)argc;
	(void)argv;
	while (1)
	{
		str = readline("minishell: ");
		args = ft_split(str, ' ');


		// AKI EU TENHO Q COMECAR A ANALIZAR OS ARGUMENTOS PASSADOS E VERIFICAR $ > >> |
		init_count(&info);
		analyze(args, &info);


		if (compare("echo", str))
			echo(args);
		else if (compare("cd", str))
			cd(str);
		else if (compare("pwd", str))
			pwd();
		else if (compare("export", str))
		{}
		else if (compare("unset", str))
		{}
		else if (compare("env", str))
		{}
		else if (compare("exit", str))
			exit_shell(args, str);
		else
			exec_program(args, env, str);
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
