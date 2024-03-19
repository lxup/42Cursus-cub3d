/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:56:19 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 12:03:30 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parsing_map_dup(t_game *game)
{
	game->map.content_dup = ft_2d_dup(game->map.content);
	if (!game->map.content_dup)
		return (ft_exit(game, ERR_MAP, "Malloc failed"));
	return (1);
}