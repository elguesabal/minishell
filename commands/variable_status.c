/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:38:31 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:40:17 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief USA free() NA ATIGA VARIAVEL "?" E ATUALIZA COM UMA NOVA
/// @param no LISTA ENCADEADA QUE ESTA A VARIAVEL "?"
/// @param str NUMERO DO STATUS RETORNADO DE OUTRO PROCESSO OU COMANDO
void	update_status(t_str **no, char *str)
{
	t_str	*assist;

	assist = *no;
	while (assist)
	{
		if (assist->str[0] == '?' && assist->str[1] == '=')
		{
			free(assist->str);
			assist->str = str;
		}
		assist = assist->next;
	}
}

/// @brief ATUALIZA A VARIAVEL "?" COM O INTEIRO status
/// @param status NUMERO DO STATUS RETORNADO DE OUTRO PROCESSO OU COMANDO
/// @param env_list LISTA LINCADA QUE ESTA A VARIAVEL "?"
void	variable_status(int status, t_str **env_list)
{
	char	*num;
	char	*new_variable;
	int		i;

	num = ft_itoa(status);
	new_variable = malloc((ft_strlen(num) + 3) * sizeof(char));
	if (new_variable == NULL)
		return ;
	new_variable[0] = '?';
	new_variable[1] = '=';
	i = 0;
	while (num[i])
	{
		new_variable[i + 2] = num[i];
		i++;
	}
	new_variable[i + 2] = '\0';
	free(num);
	update_status(env_list, new_variable);
}
