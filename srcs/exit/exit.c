/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:27:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 16:35:46 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_free_game(t_game *game)
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
	ft_free_game(game);
	return (exit(error), error);
}
