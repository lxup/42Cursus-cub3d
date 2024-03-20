/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 11:47:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reset_frame(t_game *game)
{
	if (game->frame.img.img)
	{
		mlx_destroy_image(game->win.mlx_ptr, game->frame.img.img);
		game->frame.img.img = NULL;
	}
	return (1);
}

int	ft_render(t_game *game)
{
	reset_frame(game);
	ft_raycasting(game);
	// static int	frame = 0;
	// printf("render %d\n", frame);
	// frame++;
	if (game->frame.img.img)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
			game->frame.img.img, 0, 0);
	
	return (1);
}
