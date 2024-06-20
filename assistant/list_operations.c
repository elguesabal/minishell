/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:12 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:13 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	insert_last(t_str **no, char *str)
{
	t_str	*new;
	t_str	*assist;

	new = malloc(sizeof(t_str));
	if (!new)
		return ;
	new->str = str;
	new->next = NULL;
	if (!*no)
		*no = new;
	else
	{
		assist = *no;
		while (assist->next)
			assist = assist->next;
		assist->next = new;
	}
}

void	creat_list(t_str **no, char **array_str)
{
	while (*array_str)
	{
		insert_last(no, copy_str(*array_str));
		array_str++;
	}
}

char	**array_to_list(t_str **no)
{
	char	**array;
	t_str	*assist;
	int		i;

	array = malloc((listlen(*no) + 1) * sizeof(char *));
	if (!array)
	{
		printf("Error\na funcao malloc() retornou NULL\n");
		return (NULL);
	}
	assist = *no;
	i = 0;
	while (assist)
	{
		array[i] = assist->str;
		i++;
		assist = assist->next;
	}
	array[i] = NULL;
	return (array);
}

void	free_list(t_str **no)
{
	t_str	*assist;

	assist = *no;
	while (assist)
	{
		*no = (*no)->next;
		free(assist->str);
		free(assist);
		assist = *no;
	}
}
