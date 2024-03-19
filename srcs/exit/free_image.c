/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:44:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 21:45:04 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_image(t_game *game, t_image *img)
{
	if (img->img)
	{
		mlx_destroy_image(game->win.mlx_ptr, img->img);
		img->img = NULL;
	}
	return (1);
}
