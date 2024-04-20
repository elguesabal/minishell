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
