/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:59 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:06:00 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*copy_str(char *str)
{
	char	*str2;
	int		i;

	if (str == NULL)
	{
		str = malloc(sizeof(char));
		str = '\0';
		return (str);
	}
	i = 0;
	while (str[i])
		i++;
	str2 = malloc((i + 1) * sizeof(char));
	if (str2)
	{
		str2[i] = '\0';
		while (i)
		{
			i--;
			str2[i] = str[i];
		}
	}
	return (str2);
}
