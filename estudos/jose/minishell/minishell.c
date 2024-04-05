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
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}



int	pwd(void)
{
	char	*pwd;

	if ((pwd = getcwd(NULL, 0)))
    	printf("%s\n", pwd);
    else
    {
        printf("Error\npwd nao funcionou\n");
	    free(pwd);
        return (1);
    }
	free(pwd);
	return (0);
}

int	main(void)
{
	char	*str;

	
	while (1)
	{
		str = readline("minishell: ");
		if (compare("pwd", str))
		{
			pwd();
			free(str);
		}
	}

	return (0);
}