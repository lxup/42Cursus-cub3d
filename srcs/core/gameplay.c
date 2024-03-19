/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:31:30 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 20:42:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_gameplay(t_game *game)
{
	if (game->win.width == -1 || game->win.height == -1)
		if (mlx_get_screen_size(game->win.mlx_ptr, &game->win.width, \
			&game->win.height))
			return (ft_exit(game, ERR_MLX, "Mlx failed to get screen size"));
	game->win.win_ptr = mlx_new_window(game->win.mlx_ptr, \
		game->win.width, game->win.height, "Cub3D");
	if (game->win.win_ptr == NULL)
		return (ft_exit(game, ERR_MLX, "Mlx failed to create a new window"));
	ft_hooks(game);
	mlx_loop_hook(game->win.mlx_ptr, ft_render, game);
	mlx_loop(game->win.mlx_ptr);
	return (1);
}
