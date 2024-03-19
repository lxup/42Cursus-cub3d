/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:06:47 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 11:13:21 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	destroy_image(t_game *game, t_image *img)
{
	if (img->img)
	{
		mlx_destroy_image(game->win.mlx_ptr, img->img);
		img->img = NULL;
	}
	return (1);
}

int	ft_free_texture(t_game *game)
{
	destroy_image(game, &game->textures.wall_no);
	destroy_image(game, &game->textures.wall_so);
	destroy_image(game, &game->textures.wall_we);
	destroy_image(game, &game->textures.wall_ea);
	destroy_image(game, &game->textures.sprite);
	return (1);
}