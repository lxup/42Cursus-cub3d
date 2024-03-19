/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:27:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 19:19:44 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_game *game, t_error error, char *msg)
{
	if (error)
	{
		if (error == ERR_EXIT_GAME)
			ft_dprintf(2, C_GREEN "Exit -> %s\n" C_RESET, msg);
		else
			ft_dprintf(2, C_RED "Error -> %s\n" C_RESET, msg);
	}
	ft_free_game(game);
	return (exit(error), error);
}
