/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfranco <wfranco@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/17 07:28:37 by wfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_syntax_error(char operator)
{
	printf("syntax error near '%c'\n", operator);
	return (1);
}

int check_pipe(char **arg, int i)
{
	int	error;

	error = 0;
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<')
		error += check_syntax_error(arg[i][0]);
	if (arg[i][1] == '|' || arg[i][1] == '>' || arg[i][1] == '<')
		error += check_syntax_error(arg[i][0]);
	return (error);
}

int check_greater(char **arg, int i)
{
	int	error;

	error = 0;
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '<')
		error += check_syntax_error(arg[i + 1][0]);
	if (arg[i][1] == '|' || arg[i][1] == '<')
		error += check_syntax_error(arg[i][0]);
	return (error);
}

int check_less(char **arg, int i)
{
	int	error;

	error = 0;
	if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>')
		error += check_syntax_error(arg[i + 1][0]);
	if (arg[i][1] == '|' || arg[i][1] == '>')
		error += check_syntax_error(arg[i][0]);
	return (error);
}

int check_operator(char **arg)
{
	int i;
	int	error;

	i = 0;
	error = 0;
	while (arg[i] && arg[i + 1] != NULL)
	{
		if (arg[i][0] == '|')
			error += check_pipe(arg, i);
		else if (arg[i][0] == '>')
			error += check_greater(arg, i);
		else if (arg[i][0] == '<')
			error += check_less(arg, i);
		i++;
	}
	if (arg[i][0] == '|' && (arg[i][1] == '>' || arg[i][1] == '|' || arg[i][1] == '<'))
		error += check_syntax_error(arg[i][0]);
	else if (arg[i][0] == '>' && (arg[i][1] == '|' || arg[i][1] == '<'))
		error += check_syntax_error(arg[i][0]);
	else if (arg[i][0] == '<' && (arg[i][1] == '|' || arg[i][1] == '>'))
		error += check_syntax_error(arg[i][0]);
	return (error);
}
