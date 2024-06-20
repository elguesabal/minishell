/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:15 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:37:05 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	compare_variable(char *s1, char *s2)
{
	int	i;

	if (s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && ((s2[i] >= '0' && s2[i] <= '9')
			|| (s2[i] >= 'A' && s2[i] <= 'Z')
			|| (s2[i] >= 'a' && s2[i] <= 'z') || s2[i] == '_'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	search_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	search_operator(char **argv, char operator)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == operator)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	search_next_operator(char **argv)
{
	while (*argv)
	{
		if ((*argv)[0] == '|' && (*argv)[1] == '\0')
			return (1);
		else if ((*argv)[0] == '>' && (*argv)[1] == '\0')
			return (2);
		else if ((*argv)[0] == '>' && (*argv)[1] == '>')
			return (3);
		else if ((*argv)[0] == '<' && (*argv)[1] == '\0')
			return (4);
		else if ((*argv)[0] == '<' && (*argv)[1] == '<')
			return (5);
		argv++;
	}
	return (0);
}

int	compare_str(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '\0' && *s2 == '\0');
}
