/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:23:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/04/05 19:55:53 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	compare(char *s1, char *s2)	// AUXILIAR
{
	int			i;

	i = 0;
	while ((s1[i] || s2[i]) && s2[i] != ' ' && s2[i] != '	')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}


int	main(void)
{
	char	*str;

	str = readline("minishell: ");
	while (!compare("exit", str))
	{
		if (compare("echo", str))
			echo(str);
		else if (compare("cd", str))
			cd(str);
		else if (compare("pwd", str))
			pwd();
		else if (compare("export", str))
		{}
		else if (compare("unset", str))
		{}
		else if (compare("env", str))
		{}
		else
			printf("%s: comando não encontrado\n", str);
		free(str);
		str = readline("minishell: ");
	}
	return (0);
}