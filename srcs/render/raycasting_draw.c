/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:12:36 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 18:37:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_raycasting_draw(t_game *game, int x)
{
	if (game->frame.draw_end < game->win.height)
		ft_raycasting_draw_floor(game, x);
	if (game->frame.draw_start > 0)
		ft_raycasting_draw_ceiling(game, x);
	ft_raycasting_draw_wall(game, x);
	return (1);
}
