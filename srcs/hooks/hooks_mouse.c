/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:22:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 20:25:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hook_on_mousemove(int x, int y, t_game *game)
{
	printf("hook_on_mousemove: %d, %d\n", x, y);
	(void)x;
	(void)y;
	(void)game;
	// ADD MOUSE MOVE
	return (1);
}

int	hook_on_mousepress(int button, int x, int y, t_game *game)
{
	printf("hook_on_mousepress: %d, %d, %d\n", button, x, y);
	(void)button;
	(void)x;
	(void)y;
	(void)game;
	// ADD MOUSE PRESS
	return (1);
}

int	hook_on_mouserelease(int button, int x, int y, t_game *game)
{
	printf("hook_on_mouserelease: %d, %d, %d\n", button, x, y);
	(void)button;
	(void)x;
	(void)y;
	(void)game;
	// ADD MOUSE RELEASE
	return (1);
}
