/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_circle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:21:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 13:52:42 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_mlx_draw_circle(t_image *img, t_coord origin, int radius, int color)
{
	double	angle;
	t_coord	point;
	double	i;

	i = 0;
	while (i < 360)
	{
		angle = i;
		point.x = radius * cos(angle * M_PI / 180) + origin.x;
		point.y = radius * sin(angle * M_PI / 180) + origin.y;
		custom_mlx_pixel_put(img, point.x, point.y, color);
		// custom_mlx_draw_line(img, origin, point, color);
        i += 0.1;
	}
	return (1);
}
