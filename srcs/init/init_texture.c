/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:46:14 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/18 18:53:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_img(t_game *game, t_image *img)
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

static int	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
	color->a = -1;
	return (1);
}

int	ft_init_texture(t_game *game)
{
	init_img(game, &game->textures.wall_no);
	init_img(game, &game->textures.wall_so);
	init_img(game, &game->textures.wall_we);
	init_img(game, &game->textures.wall_ea);
	init_img(game, &game->textures.sprite);
	init_color(&game->textures.ceiling);
	init_color(&game->textures.floor);
	// Add other textures here
	return (1);
}