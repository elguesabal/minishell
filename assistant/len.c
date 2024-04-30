#include "../minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/// @brief CONTA O TAMANHO DE UM ARRAY DE STRINGS
/// @param array_ptr RECEBE UM PONTEIRO DE ARRAY DE STRINGS
/// @return RETORNA A QUANTIDADE DE STRINGS
int strstrlen(char **array_ptr)
{
    int i;

    i = 0;
    while (array_ptr[i])
        i++;
    return (i);
}

/// @brief ANALIZA UMA STRING A PROCURA DE UM CHAR E RETORNA O NUMERO DA SUA POSICAO
/// @param str STRING A SER ANALIZADA
/// @param c CHAR USADO PARA ANALIZAR A STRING
/// @return RETORNA O NUMERO DA POSICAO CASO ENCONTRADO EXEMPLO: "teste$PATH", '$' RETORNA 5
/// @return RETORNA -1 CASO NAO ENCONTRE O CHAR
int	strlen_char(char *str, char c) // VOU CONFIAR NA VRIFICACAO DA FUNCAO search_dollar_sign() KKKKKKK
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}


/// @brief CONTA E RETORNA O TAMNHO DA LISTA ENCADEADA
/// @param no LISTA QUE SERA CONTADO OS ELEMENTOS
/// @return RETORNA O TAMNHO DA LISTA
int	listlen(t_str *no)
{
	t_str	*assist;
	int	i;

	assist = no;
	i = 0;
	while (assist)
	{
		assist = assist->next;
		i++;
	}
	return (i);
}
