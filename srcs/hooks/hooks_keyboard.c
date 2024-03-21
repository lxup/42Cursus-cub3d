/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:21:47 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 11:56:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_hook_on_keypress(int keycode, t_game *game)
{
	printf("ft_hook_on_keypress: %d\n", keycode);
	if (keycode == KEY_ESC)
		return (ft_hook_on_window_close(game));
	else if (keycode == KEY_W)
		game->player.move |= M_UP;
	else if (keycode == KEY_S)
		game->player.move |= M_DOWN;
	else if (keycode == KEY_A)
		game->player.move |= M_LEFT;
	else if (keycode == KEY_D)
		game->player.move |= M_RIGHT;
	else if (keycode == KEY_ARROW_TOP)
		game->player.move |= M_VIEW_UP;
	else if (keycode == KEY_ARROW_BOT)
		game->player.move |= M_VIEW_DOWN;
	else if (keycode == KEY_ARROW_LEFT)
		game->player.move |= M_VIEW_LEFT;
	else if (keycode == KEY_ARROW_RIGHT)
		game->player.move |= M_VIEW_RIGHT;
	else if (keycode == KEY_SHIFT)
		game->player.move |= M_SPRINT;
	else if (keycode == KEY_CTRL)
		game->player.move |= M_CROUCH;
	return (1);
}

int	ft_hook_on_keyrelease(int keycode, t_game *game)
{
	printf("ft_hook_on_keyrelease: %d\n", keycode);
	if (keycode == KEY_W)
		game->player.move &= ~M_UP;
	else if (keycode == KEY_S)
		game->player.move &= ~M_DOWN;
	else if (keycode == KEY_A)
		game->player.move &= ~M_LEFT;
	else if (keycode == KEY_D)
		game->player.move &= ~M_RIGHT;
	else if (keycode == KEY_ARROW_TOP)
		game->player.move &= ~M_VIEW_UP;
	else if (keycode == KEY_ARROW_BOT)
		game->player.move &= ~M_VIEW_DOWN;
	else if (keycode == KEY_ARROW_LEFT)
		game->player.move &= ~M_VIEW_LEFT;
	else if (keycode == KEY_ARROW_RIGHT)
		game->player.move &= ~M_VIEW_RIGHT;
	else if (keycode == KEY_SHIFT)
		game->player.move &= ~M_SPRINT;
	else if (keycode == KEY_CTRL)
		game->player.move &= ~M_CROUCH;
	return (1);
}
