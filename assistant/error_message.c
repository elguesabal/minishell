/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:06:03 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:06:04 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief PRINTA A MENSAGEM DE ERRO E ATUALIZA A VARIAVEL DE STATUS
/// @param message MENSAGEM DE ERRO
/// @param arg ARGUMENTOS DA MENSAGEM DE ERRO
/// @param status STATUS A SER ATUALIZADO
/// @param env_list LISTA ENCADEADA COM TODAS AS VARIAVEIS DE AMBIENTE
void	error_message(char *message, char *arg, int status, t_str **env_list)
{
	printf(message, arg);
	variable_status(status, env_list);
}
