/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:27:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 10:10:49 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reset_frame(t_game *game)
{
	if (game->win.img.img)
	{
		mlx_destroy_image(game->win.mlx_ptr, game->win.img.img);
		game->win.img.img = NULL;
	}
	game->win.img.img = mlx_new_image(game->win.mlx_ptr, \
		game->win.width, game->win.height);
	if (game->win.img.img == NULL)
		return (ft_exit(game, ERR_MLX, "Mlx failed to create a new image"));
	game->win.img.addr = mlx_get_data_addr(game->win.img.img, \
		&game->win.img.bits_per_pixel, &game->win.img.size_line, &game->win.img.endian);
	if (game->win.img.addr == NULL)
		return (ft_exit(game, ERR_MLX, "Mlx failed to get image data address"));
	return (1);
}

int	ft_render(t_game *game)
{
	reset_frame(game);
	ft_raycasting(game);
	ft_move_player(game, &game->player);
	if (game->win.img.img)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
			game->win.img.img, 0, 0);
	return (1);
}
