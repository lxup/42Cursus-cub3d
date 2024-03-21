/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:22:55 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 20:46:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	mouse_move_right(t_game *game, int diff_x, int x, int y)
{
	game->frame.mouse.x = x;
	while (diff_x != 0)
	{
		ft_move_player_view_right(game, &game->player);
		diff_x--;
	}
	if (x > (int)game->win.width * 0.7)
	{
		mlx_mouse_move(game->win.mlx_ptr, game->win.win_ptr, (int)game->win.width / 2, y);
		game->frame.mouse.x = (int)game->win.width / 2;
	}
	return (1);
}

static int	mouse_move_left(t_game *game, int diff_x, int x, int y)
{
	game->frame.mouse.x = x;
	while (diff_x != 0)
	{
		ft_move_player_view_left(game, &game->player);
		diff_x--;
	}
	if (x < (int)game->win.width * 0.3)
	{
		mlx_mouse_move(game->win.mlx_ptr, game->win.win_ptr, (int)game->win.width / 2, y);
		game->frame.mouse.x = (int)game->win.width / 2;
	}
	return (1);
}

int	ft_hook_on_mousemove(int x, int y, t_game *game)
{
	int	diff_x;

	diff_x = abs(game->frame.mouse.x - x);
	if (diff_x > 10)
		diff_x = 10;
	if (y < (int)(game->win.height * 0.3) || y > (int)(game->win.height * 0.7))
		mlx_mouse_move(game->win.mlx_ptr, game->win.win_ptr, x, (int)game->win.height / 2);
	if (x > game->frame.mouse.x)
		mouse_move_right(game, diff_x, x, y);
	else if (x < game->frame.mouse.x)
		mouse_move_left(game, diff_x, x, y);
	return (1);
}

int	ft_hook_on_mousepress(int button, int x, int y, t_game *game)
{
	printf("hook_on_mousepress: %d, %d, %d\n", button, x, y);
	(void)button;
	(void)x;
	(void)y;
	(void)game;
	// ADD MOUSE PRESS
	return (1);
}

int	ft_hook_on_mouserelease(int button, int x, int y, t_game *game)
{
	printf("hook_on_mouserelease: %d, %d, %d\n", button, x, y);
	(void)button;
	(void)x;
	(void)y;
	(void)game;
	// ADD MOUSE RELEASE
	return (1);
}
