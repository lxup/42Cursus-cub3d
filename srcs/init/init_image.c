/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:41:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 21:42:06 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_image(t_game *game, t_image *img)
{
	(void)game;
	img->img = NULL;
	img->addr = NULL;
	img->size.x = 0;
	img->size.y = 0;
	img->bits_per_pixel = 0;
	img->size_line = 0;
	img->endian = 0;
	return (1);
}
