/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/20 09:07:22 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_syntax_error(char operator)
{
	char	*s1;
	char	*s2;

	s1 = "-minishell: erro de sintaxe próximo ao token inesperado `%c'\n";
	s2 = "-minishell: erro de sintaxe próximo ao token inesperado `newline'\n";
	if (operator)
		printf(s1, operator);
	else
		printf(s2, 0);
	return (1);
}

int	check_pipe(char **arg, int i)
{
	int	error;

	error = 0;
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<')
		error += check_syntax_error(arg[i][0]);
	else if (arg[i][1] == '|' || arg[i][1] == '>' || arg[i][1] == '<')
		error += check_syntax_error(arg[i][0]);
	return (error);
}

int	check_greater(char **arg, int i)
{
	int	error;

	error = 0;
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '<')
		error += check_syntax_error(arg[i + 1][0]);
	else if (arg[i][1] == '|' || arg[i][1] == '<')
		error += check_syntax_error(arg[i][0]);
	return (error);
}

int	check_less(char **arg, int i)
{
	int	error;

	error = 0;
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>')
		error += check_syntax_error(arg[i + 1][0]);
	else if (arg[i][1] == '|' || arg[i][1] == '>')
		error += check_syntax_error(arg[i][0]);
	return (error);
}

int	check_operator(char **arg)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (arg[i] && error == 0)
	{
		if (arg[i + 1] == NULL
			&& (arg[i][0] == '|' || arg[i][0] == '>' || arg[i][0] == '<'))
		{
			error += check_syntax_error('\0');
			break ;
		}
		else if (arg[i][0] == '|')
			error += check_pipe(arg, i);
		else if (arg[i][0] == '>')
			error += check_greater(arg, i);
		else if (arg[i][0] == '<')
			error += check_less(arg, i);
		i++;
	}
	return (error);
}
