/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:05:15 by joseanto          #+#    #+#             */
/*   Updated: 2024/06/14 20:05:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief ADICIONA O HISTORICO DE OUTRAS SESSOES QUE ESTA ARMAZENADO EM CACHE
void	init_history(void)
{
	int		fd;
	char	*history;

	fd = open(".minishell_history", O_RDONLY);
	if (fd == -1)
		return ;
	history = get_next_line(fd);
	while (history)
	{
		history[ft_strlen(history) - 1] = '\0';
		add_history(history);
		free(history);
		history = get_next_line(fd);
	}
}

/// @brief ADICIONA NOVOS COMANDOS AO HISTORICO
/// @param str COMANDO A SER ADICIONADO
void	new_history(char *str)
{
	int	fd;

	if (str[0] == '\0')
		return ;
	add_history(str);
	fd = open(".history", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	close(fd);
}
