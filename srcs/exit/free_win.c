/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:03:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 11:18:50 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_win(t_game *game)
{
	if (game->win.mlx_ptr)
	{
		mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
		// mlx_destroy_display(game->win.mlx_ptr); // doesnt exist on macos
		free(game->win.mlx_ptr);
		game->win.mlx_ptr = NULL;
	}
	return (1);
}
