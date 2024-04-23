#include "../minishell.h"

/// @brief ALOCA MEMORIA PARA COPIAR E RETORNAR A STRING RECEBIDA
/// @param str STRING A SER COPIADA
/// @return RETORNA UMA STRING IDENTICA A str EM OUTRO ENDERECO DE MEMORIA
/// @return CASO str SEJA NULL RETORNA UM ENDERECO DE MEMORIA COM '\0'
char	*copy_str(char *str)
{
	char	*str2;
	int		i;

	if (str == NULL)
	{
		str = malloc(sizeof(char));
		str = '\0';
		return (str);
	}
	i = 0;
	while (str[i])
		i++;
	str2 = malloc((i + 1) * sizeof(char));
	if (str2)
	{
		str2[i] = '\0';
		while (i)
		{
			i--;
			str2[i] = str[i];
		}
	}
	return (str2);
}

/// @brief ALOCA MEMORIA PARA COPIAR E RETORNAR O ARRAY DE STRING RECEBIDO
/// @param ptr STRING A SER COPIADA
/// @return RETORNA UM ARRAY DE STRING IDENTICA A ptr EM OUTRO ENDERECO DE MEMORIA
// char	**copy_str_str(char	**ptr)
// {
// 	char	**copy;
// 	int	i;

// 	copy = malloc((strstrlen(ptr) + 1) * sizeof(char *));
// 	if (copy == NULL)
// 	{
// 		printf("Error: a funcao malloc() retornou NULL\n");
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (ptr[i])
// 	{
// 		copy[i] = copy_str(ptr[i]);
// 		i++;
// 	}
// 	copy[i] = NULL;
// 	return (copy);
// }
