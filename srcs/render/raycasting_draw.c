/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:12:36 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 19:38:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_raycasting_verline(t_game *game, int x)
{
	int	y;

	y = game->frame.draw_start;
	while (y < game->frame.draw_end)
	{
		custom_mlx_pixel_put(&game->win.img, x, y, game->frame.color);
		y++;
	}
	return (1);

}

static int	set_color(t_game *game)
{
	if (game->frame.hit_value == '1')
		game->frame.color = 0x00FF0000; // red
	else if (game->frame.hit_value == '2')
		game->frame.color = 0x0000FF00; // green
	return (1);
}

int	ft_raycasting_draw(t_game *game, int x)
{
	set_color(game);
	ft_raycasting_verline(game, x);
	return (1);
}
