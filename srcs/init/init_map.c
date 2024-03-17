/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:41:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 15:45:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_map(t_game *game, char *file)
{
	game->map.path = file;
	game->map.size.x = 0;
	game->map.size.y = 0;
	game->map.fd = -1;
	game->map.content = NULL;
	game->map.e_count = 0;
	game->map.p_count = 0;
	game->map.c_count = 0;
	game->map.k_count = 0;
	game->map.w_count = 0;
	game->map.spawn.x = 0;
	game->map.spawn.y = 0;
	return (1);
}
