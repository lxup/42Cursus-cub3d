/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:47:34 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 12:03:25 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_raycasting_init(t_game *game, int x)
{
	ft_init_frame(&game->frame);
	game->frame.camera.x = 2 * x / (double)game->win.width - 1;

	game->frame.ray_dir.x = game->player.dir.x + game->player.plane.x * game->frame.camera.x * game->settings.fov;
	game->frame.ray_dir.y = game->player.dir.y + game->player.plane.y * game->frame.camera.x * game->settings.fov;
	game->frame.map.x = game->player.pos.x;
	game->frame.map.y = game->player.pos.y;
	game->frame.delta_dist.x = fabs(1 / game->frame.ray_dir.x);
	game->frame.delta_dist.y = fabs(1 / game->frame.ray_dir.y);
	ft_raycasting_step(game);
	return (1);
}

int	ft_raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->win.width)
	{
		// printf("x: %d\n", x);
		// ft_print_frame(game->frame);
		// printf("raycasting init\n");
		ft_raycasting_init(game, x);
		// printf("raycasting dda\n");
		ft_raycasting_dda(game);
		// printf("raycasting wall\n");
		ft_raycasting_wall(game);
		// printf("raycasting draw\n");
		ft_raycasting_draw(game, x);
		// printf("raycasting end\n");
		// ft_print_frame(game->frame);
		// ft_exit(game, EXIT_SUCCESS, "raycasting end");
		x++;
	}
	return (1);
}