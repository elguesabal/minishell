/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:37 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:38 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(char **argv, t_str **env_list)
{
	char	flag;
	int		i;

	flag = '\n';
	i = 1;
	if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'n')
	{
		flag = '\0';
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	printf("%c", flag);
	variable_status(0, env_list);
}
