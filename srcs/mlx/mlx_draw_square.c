/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:07:47 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:39:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_mlx_draw_square(t_image *img, t_vector start, t_vector end, \
	int color)
{
	t_vector	origin;

	origin.x = start.x;
	origin.y = start.y;
	while ((start.y - origin.y) < end.y)
	{
		start.x = origin.x;
		while ((start.x - origin.x) < end.x)
		{
			custom_mlx_pixel_put(img, start.x, start.y, color);
			start.x++;
		}
		start.y++;
	}
	return (1);
}
