/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:09 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:10 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	strstrlen(char **array_ptr)
{
	int	i;

	i = 0;
	while (array_ptr[i])
		i++;
	return (i);
}

int	strlen_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	listlen(t_str *no)
{
	t_str	*assist;
	int		i;

	assist = no;
	i = 0;
	while (assist)
	{
		assist = assist->next;
		i++;
	}
	return (i);
}

int	len_all_variable(char *str, t_str **env_list)
{
	int		len;
	t_str	*no;

	len = 0;
	while (*str)
	{
		if (*str == '$')
		{
			no = search_variable_list(env_list, str + 1);
			if (no)
			{
				len += ft_strlen(no->str) - strlen_char(no->str, '=') - 1;
				str += strlen_char(no->str, '=');
			}
			else
			{
				while (*str && *str != ' ' && *str != '	' && *str != '$')
					str++;
			}
		}
		else
			len++;
		str++;
	}
	return (len);
}
