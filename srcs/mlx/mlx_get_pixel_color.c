/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_pixel_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:53:02 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 18:05:16 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_mlx_get_pixel_color(t_image *img, int x, int y)
{
	if (img == NULL || img->size.x == 0 || img->size.y == 0 \
		|| img->addr == NULL)
		return (0);
	x = abs(x);
	y = abs(y);
	if (x < 0 || y < 0 || x > img->size.x || y > img->size.y)
		return (0);
	return (*(int *)(img->addr + (((y * img->size.x) + x) \
		* (img->bits_per_pixel / 8))));
}
