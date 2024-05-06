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

    // ' -> 200
    // " -> 201
    // $ -> 202
    // > -> 203
    // >> -> 
    // | -> 204
    // < -> 205
    // << -> 

    if (*c == '	' && single_quotes == 0 && double_quotes == 0)
        *c = ' ';
    else if (*c == ' ' && (single_quotes == 1 || double_quotes == 1))
        *c = '	';
    else if (*c == 39 && double_quotes == 0 && single_quotes != 0)
        *c = 200;
    else if (*c == 34 && single_quotes == 0 && double_quotes != 0)
        *c = 201;
    else if (*c == '$' && single_quotes == 1)
        *c = 202;
    else if (*c == '>' && (single_quotes == 1 || double_quotes == 1))
		*c = 203;
	else if (*c == '|' && (single_quotes == 1 || double_quotes == 1))
		*c = 204;
	else if (*c == '<' && (single_quotes == 1 || double_quotes == 1))
		*c = 205;
}

// void	revert_caracter(char *str)
// {

// }

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

char	*remove_quotes(char *str)
{
    // ' -> 200
    // " -> 201
printf("chegou aki: %d\n", str[5]);

	int	i;
	int	quotes;
	int	single_quotes;
	int	double_quotes;
	char	*new_str;

	if (str == NULL)
		return (NULL);
	single_quotes = 200;
	double_quotes = 201;
	quotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == single_quotes || str[i] == double_quotes)
			quotes++;
		i++;
	}
	if (quotes == 0)
		return (str);
printf("chegou aki\n");
	new_str = malloc((ft_strlen(str) + 1 - quotes) * sizeof(char));
	if (new_str == NULL)
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] != single_quotes && str[i] != double_quotes)
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
