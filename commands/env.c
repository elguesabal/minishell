/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:07:40 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:07:41 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(char **env, t_str **env_list)
{
	if (env == NULL)
		return ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	variable_status(0, env_list);
}
