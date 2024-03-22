/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 18:16:26 by lquehec          ###   ########.fr       */
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
	game->win.frame.img = mlx_new_image(game->win.mlx_ptr, \
		game->win.width, game->win.height);
	if (game->win.frame.img == NULL)
		return (ft_exit(game, ERR_MLX, "Mlx failed to create a new image"));
	game->win.frame.addr = mlx_get_data_addr(game->win.frame.img, \
		&game->win.frame.bits_per_pixel, &game->win.frame.size_line, \
			&game->win.frame.endian);
	if (game->win.frame.addr == NULL)
		return (ft_exit(game, ERR_MLX, "Mlx failed to get image data address"));
	return (1);
}

int	ft_render(t_game *game)
{
	reset_frame(game);
	ft_raycasting(game);
	ft_minimap(game);
	ft_move_player(game, &game->player);
	if (game->win.frame.img)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
			game->win.frame.img, 0, 0);
	return (1);
}
