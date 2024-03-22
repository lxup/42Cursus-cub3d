/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:35:44 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:54:39 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_raycasting_draw_floor_verline(t_game *game, int x, int y, \
	int draw_end)
{
	int	color;

	color = ft_color_to_int(game->textures.floor);
	while (y < draw_end)
	{
		custom_mlx_pixel_put(&game->win.frame, x, y, color);
		y++;
	}
	return (1);
}

int	ft_raycasting_draw_floor(t_game *game, int x)
{
	ft_raycasting_draw_floor_verline(game, x, game->frame.draw_end, \
		game->win.height);
	return (1);
}
