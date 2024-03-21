/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:31:30 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 20:00:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_gameplay(t_game *game)
{
	if (game->win.width == -1 || game->win.height == -1)
		if (custom_mlx_get_screen_size(game->win.mlx_ptr, &game->win.width, \
			&game->win.height))
			return (ft_exit(game, ERR_MLX, "Mlx failed to get screen size"));
	if (game->win.width > MAX_WIDTH)
		game->win.width = MAX_WIDTH;
	if (game->win.height > MAX_HEIGHT)
		game->win.height = MAX_HEIGHT;
	game->win.win_ptr = mlx_new_window(game->win.mlx_ptr, \
		game->win.width, game->win.height, WINDOW_TITLE);
	if (game->win.win_ptr == NULL)
		return (ft_exit(game, ERR_MLX, "Mlx failed to create a new window"));
	ft_init_game(game);
	ft_hooks(game);
	mlx_loop_hook(game->win.mlx_ptr, ft_render, game);
	mlx_loop(game->win.mlx_ptr);
	return (1);
}
