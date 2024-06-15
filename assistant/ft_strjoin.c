/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:06:25 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:06:26 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char *rest_line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rest_line)
	{
		rest_line = (char *)malloc(1 * sizeof(char));
		rest_line[0] = '\0';
	}
	if (!rest_line || !buffer)
		return (NULL);
	str = malloc(sizeof(char)
			* ((ft_strlen(rest_line) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rest_line)
		while (rest_line[++i])
			str[i] = rest_line[i];
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(rest_line) + ft_strlen(buffer)] = '\0';
	free(rest_line);
	return (str);
}
