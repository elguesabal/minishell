/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:18 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:19 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*skip_char(char *str)
{
	while (*str && *str != ' ' && *str != '	')
		str++;
	return (str);
}

char	*skip_space(char *str)
{
	while (*str && (*str == ' ' || *str == '	'))
		str++;
	return (str);
}

char	*skip_c(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (&str[i]);
}
