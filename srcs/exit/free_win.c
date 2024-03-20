/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:03:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 19:37:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_win(t_game *game)
{
	free_image(game, &game->win.img);
	if (game->win.mlx_ptr)
	{
		if (game->win.win_ptr)
			mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
		mlx_destroy_display(game->win.mlx_ptr);
		free(game->win.mlx_ptr);
		game->win.mlx_ptr = NULL;
	}
	return (1);
}