/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:06:47 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:35:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_texture(t_game *game)
{
	free_image(game, &game->textures.wall_no);
	free_image(game, &game->textures.wall_so);
	free_image(game, &game->textures.wall_we);
	free_image(game, &game->textures.wall_ea);
	free_image(game, &game->textures.ennemy);
	free_image(game, &game->textures.door);
	return (1);
}
