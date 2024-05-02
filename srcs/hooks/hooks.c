/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:03:07 by lquehec           #+#    #+#             */
/*   Updated: 2024/05/02 17:05:07 by lquehec          ###   ########.fr       */
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
	mlx_hook(game->win.win_ptr, H_KEYPRESS, H_MASK_KEYPRESS, \
		&ft_hook_on_keypress, game);
	mlx_hook(game->win.win_ptr, H_KEYRELEASE, H_MASK_KEYRELEASE, \
		&ft_hook_on_keyrelease, game);
	mlx_hook(game->win.win_ptr, H_EXIT, H_MASK_EXIT, \
		&ft_hook_on_window_close, game);
	custom_mlx_mouse_hide(game->win.mlx_ptr, game->win.win_ptr);
	mlx_hook(game->win.win_ptr, H_MOUSEMOVE, H_MASK_MOUSEMOVE, \
		&ft_hook_on_mousemove, game);
	return (1);
}
