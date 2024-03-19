/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:37:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/18 19:24:29 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_parsing_error(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && game->parsing.no)
		return (ft_exit(game, ERR_ARGS, "North texture is already set."));
	if (!ft_strncmp(line, "SO ", 3) && game->parsing.so)
		return (ft_exit(game, ERR_ARGS, "South texture is already set."));
	if (!ft_strncmp(line, "WE ", 3) && game->parsing.we)
		return (ft_exit(game, ERR_ARGS, "West texture is already set."));
	if (!ft_strncmp(line, "EA ", 3) && game->parsing.ea)
		return (ft_exit(game, ERR_ARGS, "East texture is already set."));
	if (!ft_strncmp(line, "S ", 2) && game->parsing.s)
		return (ft_exit(game, ERR_ARGS, "Sprite texture is already set."));
	if (!ft_strncmp(line, "F ", 2) && game->parsing.f)
		return (ft_exit(game, ERR_ARGS, "Floor color is already set."));
	if (!ft_strncmp(line, "C ", 2) && game->parsing.c)
		return (ft_exit(game, ERR_ARGS, "Ceiling color is already set."));
	return (ft_exit(game, ERR_ARGS, "Element missing or invalid."));
}

int	ft_parsing_line(t_game *game, char *line)
{
	if (*line == '\n' && !game->parsing.map)
		return (1);
	if ((!ft_strncmp(line, "NO ", 3) && !game->parsing.no)
		|| (!ft_strncmp(line, "SO ", 3) && !game->parsing.so)
		|| (!ft_strncmp(line, "WE ", 3) && !game->parsing.we)
		|| (!ft_strncmp(line, "EA ", 3) && !game->parsing.ea)
		|| (!ft_strncmp(line, "S ", 2) && !game->parsing.s))
		return (ft_parsing_texture(game, line));
	if ((!ft_strncmp(line, "F ", 2) && !game->parsing.f)
		|| (!ft_strncmp(line, "C ", 2) && !game->parsing.c))
		return (ft_parsing_color(game, line));
	if (!game->parsing.succes && game->parsing.map && *line == '\n')
		return (ft_exit(game, ERR_MAP, "Map is not valid."));
	if (game->parsing.map || (!game->parsing.map && *line
		&& (game->parsing.no && game->parsing.so && game->parsing.we
		&& game->parsing.ea && game->parsing.s && game->parsing.f
		&& game->parsing.c)))
		return (ft_parsing_map(game, line));
	return (ft_parsing_error(game, line));
}
