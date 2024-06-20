/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:29 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:05:30 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	swap_tab(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '	')
				args[i][j] = ' ';
			j++;
		}
		i++;
	}
}

int	closing_quotes(char *str, char quotes)
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

void	swap_caracter(char *c, int single_quotes, int double_quotes)
{
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
