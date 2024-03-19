/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_leak.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:18:21 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 20:12:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parsing_map_leak(t_game *game, int x, int y)
{
	if (game->map.content[y][x] == '0' || ft_contains_char("NSWE", game->map.content[y][x]))
	{
		if (x == 0 || x == game->map.size.x - 1 || y == 0 || y == game->map.size.y - 1)
			return (ft_exit(game, ERR_MAP, "Map is not surrounded by 1"));
		if (game->map.content[y][x + 1] == '\0'
			|| game->map.content[y][x - 1] == '\0'
			|| game->map.content[y + 1][x] == '\0'
			|| game->map.content[y - 1][x] == '\0')
			return (ft_exit(game, ERR_MAP, "Map is not surrounded by 1"));
		if (game->map.content[y][x + 1] == ' '
			|| game->map.content[y][x - 1] == ' '
			|| game->map.content[y + 1][x] == ' '
			|| game->map.content[y - 1][x] == ' ')
			return (ft_exit(game, ERR_MAP, "Map is not surrounded by 1"));
	}
	if (x < game->map.size.x - 1 && game->map.content[y][x + 1] != '\0')
		return (ft_parsing_map_leak(game, x + 1, y));
	else if (y < game->map.size.y - 1 && game->map.content[y + 1] != NULL)
		return (ft_parsing_map_leak(game, 0, y + 1));
	return (1);
}
