/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:29 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:05:30 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief FUNCAO RESPONSAVEL POR GERENCIAR ABERTURA DE ASPAS, GARANTIR A EXISTENCIA DE FECHAMENTO, NAO INTERPRETAR ASPAS DENTRO DE ASPAS E CHAMAR A FUNCAO swap_caracter()
/// @param str STRING QUE SERA PERCORRIDA
void	quotes(char *str)
{
	int	single_quotes;
	int	double_quotes;

	single_quotes = 0;
	double_quotes = 0;
	while (*str)
	{
		if (*str == 39 && double_quotes == 0
			&& (single_quotes == 1 || closing_quotes(str, 39)))
			single_quotes++;
		else if (*str == 34 && single_quotes == 0
			&& (double_quotes == 1 || closing_quotes(str, 34)))
			double_quotes++;
		swap_caracter(str, single_quotes, double_quotes);
		if (single_quotes == 2)
			single_quotes = 0;
		else if (double_quotes == 2)
			double_quotes = 0;
		str++;
	}
}

/// @brief REMOVE AS ASPAS COM VALORES ALTERNATIVOS ' == -1 E " == -2 REUTILIZANDO O ANTIGO ENDERECO DE MEMORIA E COLOCANDO '\0' NO FIM DA STRING EXEMPLO: "teste"\0 -> teste\0"\0
/// @param str STRING QUE SERA REMOVIDA AS ASPAS
void	remove_quotes(char *str)
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
