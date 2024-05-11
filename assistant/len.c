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

int	len_all_variable(char *str, t_str **env_list)
{
	// int	i;
	int	len;
	t_str	*no;

	// i = 0;
	len = 0;
	while (*str)
	{
		if (*str == '$')
		{
			// i += TAMANHO DA VARIAVEL
			no = search_variable_list(env_list, str + 1); // $PWD -> PWD=/nfs/homes/joseanto/minishell
			if (no)
			{
				len += ft_strlen(no->str) - strlen_char(no->str, '=') - 1; // ESTOU INCREMENTANDO NA CONTAGEM POREM TBM USO i PARA MARCAR O INDICE
// printf("variavel: %s -> ft_strlen(no->str): %ld -> strlen_char(str, '='): %d\n", no->str, ft_strlen(no->str), strlen_char(no->str, '='));
// (void)no;
// if (no == NULL)
// 	printf("NULL\n");
// printf("len_all_variable: %s\n", no->str);

				// while (*str && ((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z') || *str == '_')) // ALTERNATIVA BURRA PARA str += strlen_char(no->str, '=');
				// 	str++;

				str += strlen_char(no->str, '=');
			}
			else
			{
				while (*str && *str != ' ')
					str++;
			}
		}
		else
			len++;
		str++;
	}
// printf("len: %d\n", len);
	return (len);
}
