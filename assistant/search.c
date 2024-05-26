#include "../minishell.h"

/// @brief PROCURA UMA ESTRING NO COMECO DE OUTRA LEVANADO EM CONSIDERACAO O FINAL DA COMPARACAO
/// @param s1 STRING A SER COMPARADA
/// @param s2 STRING A SER COMPARADA
/// @return SE AO FINAL DA COMPARACAO TENHA ' ' '	' OU '\0' RETORNA 1 EXEMPLO: "ls", "ls -all" ou "pwd", "pwd"
/// @return CASO NO FINAL DA COMPARACAO TENHA ALGO DIFERENTE RETORNA 0 EXEMPLO: "ls", "ls-all" ou "pwd", "pwdx"
int	compare(char *s1, char *s2)
{
	int			i;

	if (s2 == NULL)
		return (0);
	i = 0;
	// while ((s1[i] || s2[i]) && s2[i] != ' ' && s2[i] != '	') // CONDICAO USADA ANTES DA FUNCAO compare() RECEBER args[0] (ANTES RECEBIA str)
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/// @brief PROCURA UMA ESTRING NO COMECO DE OUTRA LEVANDO EM CONSIDERACAO O FINAL DA COMPARACAO
/// @param s1 STRING A SER COMPARADA
/// @param s2 STRING A SER COMPARADA
/// @return SE AO FINAL DA COMPARACAO TENHA '\0' em s1 e '=' em s2 RETORNA 1 EXEMPLO: "PWD", "PWD=/home/jose/programacao/minishell"
int	compare_variable(char *s1, char *s2) // "teste$PWD teste" -> teste/home/jose/programacao/minishell teste // NA TEORIA ISSO NAO ACONTECERIA COM O CODIGO Q ESTA COMENTADO
{
	// int			i;

	// if (s2 == NULL)
	// 	return (0);
	// i = 0;
	// while (s1[i] && s2[i] && s2[i] != ' ' && s2[i] != '	' && s2[i] != '$') // while (s1[i] && s2[i]) // TENTANTO ARRUMAR O ERRO DE NAO CONSEGUIR INTERPRETAR NADA DPS DO NOME DA VARIAVEL NO MESMO ARGUMENTO
	// {
	// 	if (s1[i] != s2[i])
	// 		return (0);
	// 	i++;
	// }
	// if ((s1[i] == '=' && s2[i] == '\0') || (s1[i] == '=' && s2[i] == ' ') || (s1[i] == '=' && s2[i] == '	') || (s1[i] == '=' && s2[i] == '$')) // if (s1[i] == '=' && s2[i] == '\0') // TENTANTO ARRUMAR O ERRO DE NAO CONSEGUIR INTERPRETAR NADA DPS DO NOME DA VARIAVEL NO MESMO ARGUMENTO
	// 	return (1);
	// else
	// 	return (0);


// printf("compare: %s\n", s2);

	int			i;

	if (s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && ((s2[i] >= '0' && s2[i] <= '9') || (s2[i] >= 'A' && s2[i] <= 'Z') || (s2[i]>= 'a' && s2[i] <= 'z') || s2[i] == '_')) // while (s1[i] && s2[i]) // TENTANTO ARRUMAR O ERRO DE NAO CONSEGUIR INTERPRETAR NADA DPS DO NOME DA VARIAVEL NO MESMO ARGUMENTO
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}


/// @brief PROCURA UM CHAR DENTRO DE UMA ESTRING
/// @param str STRING A SER ANALIZADA
/// @param c CARACTER A SER PROCURADO
/// @return RETORNA 1 CASO ENCONTRE O CARACTER c E 0 CASO NAO ENCONTRE
int	search_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

/// @brief PROCURA UM OPERADOR DE REDIRECIONAMENTO DENTRO DE UMA ARRYA DE STRINGS (PROCURA POR 1 CHAR DE OPERADOR E NAO POR 2) EXEMPLO: ">>"
/// @param argv ARRAY DE STRING A SER ANALIZADA
/// @param operator OPERADOR PASSADO A SER PROCURADO
/// @return RETORNA 1 CASO ENCONTRE O OPERADOR E 0 CASO NAO ENCONTRE
int	search_operator(char **argv, char operator)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == operator)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
