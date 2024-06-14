/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:04:54 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:04:55 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief CONTA O TAMANHO QUE A STRING DEVERIA TER CASO OS OPERADORES DE REDIRECIONAMENTO ESTIVESSEM SEPARADOS
/// @param str RECEBE UM PONTEIRO DE ARRAY DE CHAR COM ARGUMENTOS
/// @return RETORNA O TAMANHO DA STRING QUE DEVERIA TER
int	len_separating_operators(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '	' && *str != '|' && *str != '>'
			&& *str != '<'
			&& (*(str + 1) == '|' || *(str + 1) == '>' || *(str + 1) == '<'))
			len++;
		else if ((*str == '|' || *str == '>' || *str == '<')
			&& *(str + 1) != ' ' && *(str + 1) != '	'
			&& *(str + 1) != '|' && *(str + 1) != '>'
			&& *(str + 1) != '<' && *(str + 1) != '\0')
			len++;
		len++;
		str++;
	}
	return (len);
}

/// @brief SEPARA OS OPERADORES DE REDIRECIONAMENTO DE OUTROS ARGUMENTOS
/// @param str RECEBE UM PONTEIRO DE ARRAY DE CHAR COM ARGUMENTOS
/// @param copy_str ENDERECO DE MEMORIA COM O TAMANHO CORRETO PARA SEPARA OS OPERADORES DE REDIRECIONAMENTO
void	new_args(char **str, char **copy_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[0][i])
	{
		copy_str[0][i + j] = str[0][i];
		if (str[0][i] != ' ' && str[0][i] != '	' && str[0][i] != '|'
			&& str[0][i] != '>' && str[0][i] != '<' && (str[0][i + 1] == '|'
				|| str[0][i + 1] == '>' || str[0][i + 1] == '<') && ++j)
		{
			copy_str[0][i + j] = ' ';
		}
		else if ((str[0][i] == '|' || str[0][i] == '>' || str[0][i] == '<')
			&& str[0][i + 1] != ' ' && str[0][i + 1] != '	'
			&& str[0][i + 1] != '|' && str[0][i + 1] != '>'
			&& str[0][i + 1] != '<' && str[0][i + 1] && ++j)
		{
			copy_str[0][i + j] = ' ';
		}
		i++;
	}
	copy_str[0][i + j] = '\0';
}

/// @brief ALOCA UM NOVO ENDERECO DE MEMORIA E SEPARA OS OPERADORES DE REDIRECIONAMENTO DE OUTROS ARGUMENTOS POR UM ESPACO (USA free() NO ANTIGO ENDERECO DE MEMORIA)
/// @param str RECEBE UM PONTEIRO DE CHAR COM ARGUMENTOS
/// @return RETORNA UM NOVO ENDERECO DE MEMORIA COM OS AGUMENTOS SEPARADOS
void	separate_redirection_operators(char **str)
{
	char	*copy_str;

	if (!(search_char(*str, '|') || search_char(*str, '>') || search_char(*str, '<')))
		return ;
	copy_str = malloc((len_separating_operators(*str) + 1) * sizeof(char));
	if (copy_str == NULL)
		return ;
	new_args(str, &copy_str);
	free(*str);
	*str = copy_str;
}

int	argument_management(char **str, char ***argv, t_str **env_list)
{
	int	i;

	quotes(*str);
	remove_quotes(*str);
	separate_redirection_operators(str);
	*argv = ft_split(*str, ' ');
	swap_tab(*argv);
	i = 0;
	while (argv[0][i])
	{
		argv[0][i] = environment_variable(argv[0][i], env_list);
		i++;
	}
	return (0);
}
