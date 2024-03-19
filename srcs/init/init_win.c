/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:50:24 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 21:43:41 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_win(t_game *game)
{
	game->win.mlx_ptr = NULL;
	game->win.win_ptr = NULL;
	game->win.height = -1;
	game->win.width = -1;
	ft_init_image(game, &game->win.frame);
	return (1);
}
