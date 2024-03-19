/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:50:24 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/18 17:57:19 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_win(t_game *game)
{
	game->win.mlx_ptr = NULL;
	game->win.win_ptr = NULL;
	game->win.height = 0;
	game->win.width = 0;
	return (1);
}
