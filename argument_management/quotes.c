#include "../minishell.h"

// /// @brief TROCA TODOS AS TABULACAO POR ESPACOES
// /// @param str STRING QUE SERA PERCORRIDA
// void	swap_space(char *str)
// {
// 	while (*str)
// 	{
// 		if (*str == '	')
// 			*str = ' ';
// 		str++;
// 	}
// }

/// @brief VERIFICA SE AS ASPAS ABERTAS NO ENDERECO PASSADO ESTAO SENDO FECHADAS MAIS A FRENTE
/// @param str STRING ANALIZADA
/// @param quotes ASPAS QUE VAO SER PROCURADAS A FRENTE
/// @return RETORNA 1 CASO EXISTA FECHAMENTO DE ASPAS POSTERIORMENTE
/// @return RETORNA 0 CASO str SEJA NULL OU O PRIMEIRO ELEMENTO DE str NAO SEJA ASPAS MENCIONADA OU NAO EXISTA FECHAMENTO DE ASPAS
int closing_quotes(char *str, char quotes)
{
    if (str == NULL || *str != quotes)
        return (0);
    while (*str)
    {
        str++;
        if (*str == quotes)
            return (1);
    }
    return (0);
}

/// @brief TROCA METACARACTERES FORA DE ASPAS PARA NAO SEREM INTERPRETADOS DENTRO DA FUNCAO argument_management() (ASPAS TBM SAO TROCADOS PARA SEREM REMOVIDO FACILMENTE)
/// @param c CARACTER A SER ANALIZADO E TROCADO
/// @param single_quotes SINALIZADOR QUE IDENTIFICA EXISTENCIA DE ASPAS ABERTAS
/// @param double_quotes SINALIZADOR QUE IDENTIFICA EXISTENCIA DE ASPAS ABERTAS
void    swap_caracter(char *c, int single_quotes, int double_quotes)
{
    // TABELA ASCII
    // " == 34
    // ' == 39

    // ' -> 200 -> -1
    // " -> 201 -> -2
    // $ -> 202 -> -3
    // > -> 203 -> -4
    // >> -> 
    // | -> 204 -> -5
    // < -> 205 -> -6
    // << -> 
	// SPACE -> -7
	// TAB -> -8

    if (*c == '	' && single_quotes == 0 && double_quotes == 0)
        *c = ' ';
    else if (*c == ' ' && (single_quotes == 1 || double_quotes == 1))
        *c = '	';
    else if (*c == 39 && double_quotes == 0 && single_quotes != 0)
        *c = -1;
    else if (*c == 34 && single_quotes == 0 && double_quotes != 0)
        *c = -2;
    else if (*c == '$' && single_quotes == 1)
        *c = -3;
    else if (*c == '>' && (single_quotes == 1 || double_quotes == 1))
		*c = -4;
	else if (*c == '|' && (single_quotes == 1 || double_quotes == 1))
		*c = -5;
	else if (*c == '<' && (single_quotes == 1 || double_quotes == 1))
		*c = -6;
}

/// @brief FUNCAO RESPONSAVEL POR GERENCIAR ABERTURA DE ASPAS, GARANTIR A EXISTENCIA DE FECHAMENTO, NAO INTERPRETAR ASPAS DENTRO DE ASPAS E CHAMAR A FUNCAO swap_caracter()
/// @param str STRING QUE SERA PERCORRIDA
void	quotes(char *str)
{
    // TABELA ASCII
    // " == 34
    // ' == 39

	int	single_quotes;
	int	double_quotes;

	single_quotes = 0;
	double_quotes = 0;
	while (*str)
	{
		if (*str == 39 && double_quotes == 0 && (single_quotes == 1 || closing_quotes(str, 39)))
			single_quotes++;
		else if (*str == 34 && single_quotes == 0 && (double_quotes == 1 || closing_quotes(str, 34)))
			double_quotes++;

        swap_caracter(str, single_quotes, double_quotes);

		if (single_quotes == 2)
			single_quotes = 0;
		else if (double_quotes == 2)
			double_quotes = 0;

		str++;
	}
}

/// @brief REMOVE AS ASPAS COM VALORES ALTERNATIVOS ' == -1 E " == -2
/// @param str STRING QUE SERA REMOVIDA AS ASPAS
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM A MESMA STRING MAS SEM AS ASPAS MODIFICADAS (USA free() NO ANTIGO ENDERECO)
/// @return RETORNA O PROPRIO ENDERECO DE str CASO NAO TENHA ASPAS MODIFICADA
// char	*remove_quotes(char *str)
// {
//     // ' -> 200 -> -1
//     // " -> 201 -> -2

// 	int	i;
// 	int	j;
// 	int	quotes;
// 	char	*new_str;

// 	if (str == NULL)
// 		return (NULL);
// 	quotes = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == -1 || str[i] == -2)
// 			quotes++;
// 		i++;
// 	}
// 	if (quotes == 0)
// 		return (str);
// 	new_str = malloc((ft_strlen(str) + 1 - quotes) * sizeof(char));
// 	if (new_str == NULL)
// 		return (str);
// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != -1 && str[i] != -2)
// 		{
// 			new_str[j] = str[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	new_str[j] = '\0';
// 	free(str);
// 	return (new_str);
// }

/// @brief REMOVE AS ASPAS COM VALORES ALTERNATIVOS ' == -1 E " == -2 REUTILIZANDO O ANTIGO ENDERECO DE MEMORIA E COLOCANDO '\0' NO FIM DA STRING EXEMPLO: "teste"\0 -> teste\0"\0
/// @param str STRING QUE SERA REMOVIDA AS ASPAS
void	remove_quotes(char *str) // ALTERNATIVA DE char *remove_quotes(char *str) (NAO ESTRAPOLA AS 25 LINHAS E NAO ALLOCA NOVA MEMORIA)
{
	int	quotes;

	quotes = 0;
	while (*str)
	{
		if (*str != -1 && *str != -2)
			*(str - quotes) = *str;
		else
			quotes++;
		str++;
	}
	*(str - quotes) = '\0';
}

/// @brief REVERTE AS MUDIFICACOES FEITAS NAS STRINGS POR swap_caracter() EXEMPLO: char c == -3 VAI RECEBER $
/// @param args STRINGS A SEREM REVERTIDAS
void	revert_caracter(char **args)
{
    // ' -> 200 -> -1
    // " -> 201 -> -2
    // $ -> 202 -> -3
    // > -> 203 -> -4
    // >> -> 
    // | -> 204 -> -5
    // < -> 205 -> -6
    // << -> 
	// SPACE -> -7
	// TAB -> -8

	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == -3)
				args[i][j] = '$';
			else if (args[i][j] == -4)
				args[i][j] = '>';
			else if (args[i][j] == -5)
				args[i][j] = '|';
			else if (args[i][j] == -6)
				args[i][j] = '<';
			j++;
		}
		i++;
	}
}
