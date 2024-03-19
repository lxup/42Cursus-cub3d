/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:03:07 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 20:29:44 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_hook_on_window_close(t_game *game)
{
	return (ft_exit(game, ERR_EXIT_GAME, "U closed the window!"));
}

int	ft_hooks(t_game *game)
{
	mlx_do_key_autorepeatoff(game->win.mlx_ptr);
	if (ft_strcmp(OS, "macos") == 0)
	{
		mlx_hook(game->win.win_ptr, 2, 0, &ft_hook_on_keypress, game);
		mlx_hook(game->win.win_ptr, 3, 0, &ft_hook_on_keyrelease, game);
		mlx_hook(game->win.win_ptr, 17, 1L << 0, &ft_hook_on_window_close, game);
	}
	else
	{
		mlx_hook(game->win.win_ptr, 2, 1L << 0, &ft_hook_on_keypress, game);
		mlx_hook(game->win.win_ptr, 3, 2L << 0, &ft_hook_on_keyrelease, game);
		mlx_hook(game->win.win_ptr, 17, 0, &ft_hook_on_window_close, game);
	}
	return (1);
}
