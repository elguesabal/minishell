/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:04:31 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void check_operator(char **arg)
{
    int i;

i = 0;
while (arg[i] && arg[i + 1] != NULL)
{
	if (arg[i][0] == '|')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '>')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '<')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '<')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	else if (arg[i][0] == '<')
	{
		if (arg[i + 1][0] == '|' || arg[i + 1][0] == '>')
		{
			printf("syntax error near '%c'\n", arg[i + 1][0]);
			return ;
		}
		if (arg[i][1] == '|' || arg[i][1] == '>')
		{
			printf("syntax error near '%c'\n", arg[i][0]);
			return ;
		}
	}
	i++;
}
	if (arg[i][0] == '|' && (arg[i][1] == '>' || arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '>' && (arg[i][1] == '|' || arg[i][1] == '<'))
		printf("syntax error near '%c'\n", arg[i][0]);
	else if (arg[i][0] == '<' && (arg[i][1] == '|' || arg[i][1] == '>'))
		printf("syntax error near '%c'\n", arg[i][0]);
}
