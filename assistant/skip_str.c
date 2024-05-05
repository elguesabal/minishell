#include "../minishell.h"

/// @brief CAMINHA COM O ENDERECO DE MEMORIA ATE ENCONTRAR ESPACO OU TABULACAO
/// @param str STRING QUE SERA USADA
/// @return RETORNA O ENDERECO DO PRIMEIRO ESPACO OU TABULACAO ENCONTRADO
char	*skip_char(char *str)
{
	while (*str && *str != ' ' && *str != '	')
		str++;
	return (str);
}

/// @brief CAMINHA COM O ENDERECO DE MEMORIA ATE ENCONTRAR ALGO DIFERENTE DE ESPACO OU TABULACAO
/// @param str STRING QUE SERA USADA
/// @return RETORNA O ENDERECO DO PRIMEIRO ELEMENTO DIFERENTE DE ESPACO OU TABULACAO ENCONTRADO
char	*skip_space(char *str)
{
	while (*str && (*str == ' ' || *str == '	'))
		str++;
	return (str);
}

/// @brief CAMINHA COM O ENDERECO DE MEMORIA ATE ENCONTRAR O CONTEUDO DE c
/// @param str STRING QUE SERA PERCORRIDA
/// @param c CHAR Q SERA USADO COMO REFERENCIA PARA PARAR O WHILE
/// @return RETORNA O ENDERECO DO PRIMEIRO ELEMENTO DIFERENTE DO CHAR c
/// @return RETORNA NULL CASO str SEJA NULL
char	*skip_c(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != c)
		i++;
	return (&str[i]);
}

/// @brief TROCA TODOS AS TABULACAO POR ESPACOES
/// @param str STRING QUE SERA PERCORRIDA
void	swap_space(char *str)
{
	int	single_quotes;
	int	double_quotes;

	single_quotes = 0;
	double_quotes = 0;
	while (*str)
	{
		if (*str == 39)
			single_quotes++;
		else if (*str == 34)
			double_quotes++;

		if (single_quotes == 2)
			single_quotes = 0;
		else if (double_quotes == 2)
			double_quotes = 0;

		if (*str == '	' && single_quotes == 0 && double_quotes == 0)
			*str = ' ';
		else if (*str == ' ' && (single_quotes == 1 || double_quotes == 1))
			*str = '	';
		str++;
	}
}
