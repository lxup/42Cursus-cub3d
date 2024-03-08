/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:27:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/08 12:39:00 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_game(t_game *game)
{
	(void)game;
	return (1);
}

int	ft_exit(t_game *game, t_error error, char *msg)
{
	if (error)
	{
		ft_dprintf(2, C_RED "Error -> %s\n" C_RESET, msg);
	}
	fr_free_game(game);
	return (ext(error));
}
