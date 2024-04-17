#include "../minishell.h"

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
	while (*new_str)
	{
		copy_new[i] = *new_str;
		new_str++;
		i++;
	}
	copy_new[i] = '\0';
	return (copy_new);
}

// void	analyze_argument_management(char *arg) // NAO SEI ONDE TO ERRANDO MAS QUANDO CHAMO ESSA FUNCAO ESSE ERRO ACONTECE: free(): double free detected in tcache 2		Abortado (imagem do núcleo gravada)
// {
// 	if (search_dollar_sign(arg))
// 	{
// 		// info->dollar_sign++;
// printf("teste: %s", &arg[strlen_char(arg, '$') + 1]);
// 		arg = expand_variable(arg, getenv(&arg[strlen_char(arg, '$') + 1]));
// 	}
// }
