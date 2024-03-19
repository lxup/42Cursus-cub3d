/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 23:21:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reset_frame(t_game *game)
{
	if (game->win.frame.img)
	{
		mlx_destroy_image(game->win.mlx_ptr, game->win.frame.img);
		game->win.frame.img = NULL;
	}
	return (1);
}

int	ft_render(t_game *game)
{
	reset_frame(game);
	static int	frame = 0;
	printf("render %d\n", frame);
	frame++;
	if (game->win.frame.img)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
			game->win.frame.img, 0, 0);
	
	return (1);
}
