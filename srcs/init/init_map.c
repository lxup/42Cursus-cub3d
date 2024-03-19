/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:41:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 18:05:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_map(t_game *game, char *file)
{
	game->map.path = file;
	game->map.size.x = -1;
	game->map.size.y = -1;
	game->map.fd = -1;
	game->map.content = NULL;
	game->map.content_list = NULL;
	game->map.spawn.x = -1;
	game->map.spawn.y = -1;
	return (1);
}
