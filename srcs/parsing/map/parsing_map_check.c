/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:28:19 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 12:05:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parsing_map_check(t_game *game)
{
	if (game->map.spawn.x == -1 || game->map.spawn.y == -1)
		return (ft_exit(game, ERR_MAP, "No spawn point found in the map"));
	ft_parsing_map_create(game);
	ft_parsing_map_dup(game);
	ft_parsing_map_floodfill(game);
	ft_2d_putstr(game->map.content);
	return (1);
}