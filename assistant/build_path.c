#include "../minishell.h"

/// @brief CONCATENA O PRIMEIRO ARGUMENTO COM O SEGUNDO EM UM NOVO ENDERECO DE MEMORIA ADICIONANDO UM '/' NO MEIO
/// @param str1 STRING QUE SERA COPIADA ANTES DA '/'
/// @param str2 STRING QUE SERA COPIADA APOS DA '/'
/// @return RETORNA UM ENDERECO DE MEMORIA CASO PASSADO DUAS ESTRING EXEMPLO: concatenate("ft", "42") == "ft/42"
/// @return RETORNA NULL CASO ALGUM PARAMETRO SEJA NULL OU TENHA ERRO NA FUNCAO malloc() EXEMPLO: concatenate("ft", NULL) == NULL
char    *build_path(char *str1, char *str2)
{
    char    *str;
	int	i;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    str = malloc((ft_strlen(str1) + ft_strlen(str2) + 2) * sizeof(char));
	if (str == NULL)
	{
		printf("Error: a funcao malloc() retornou NULL\n");
		return (NULL);
	}
	i = 0;
	while (*str1)
	{
		str[i] = *str1;
		i++;
		str1++;
	}
	str[i] = '/';
	i++;
	while (*str2)
	{
		str[i] = *str2;
		i++;
		str2++;
	}
	str[i] = '\0';
    return (str);
}
