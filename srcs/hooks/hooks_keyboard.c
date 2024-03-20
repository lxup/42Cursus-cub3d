/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:21:47 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 20:00:09 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_hook_on_keypress(int keycode, t_game *game)
{
	printf("ft_hook_on_keypress: %d\n", keycode);
	if (keycode == KEY_ESC)
		return (ft_hook_on_window_close(game));
	else if (keycode == KEY_W)
	// ADD OTHER KEYCODES
	return (1);
}

int	ft_hook_on_keyrelease(int keycode, t_game *game)
{
	printf("ft_hook_on_keyrelease: %d\n", keycode);
	(void)keycode;
	(void)game;
	// ADD KEY RELEASE
	return (1);
}
