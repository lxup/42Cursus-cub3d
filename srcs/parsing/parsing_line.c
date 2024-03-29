/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:37:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:49:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_parsing_error(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && (game->parsing.step & PARSING_NO))
		return (ft_exit(game, ERR_ARGS, "North texture set multiple times."));
	if (!ft_strncmp(line, "SO ", 3) && (game->parsing.step & PARSING_SO))
		return (ft_exit(game, ERR_ARGS, "South texture set multiple times."));
	if (!ft_strncmp(line, "WE ", 3) && (game->parsing.step & PARSING_WE))
		return (ft_exit(game, ERR_ARGS, "West texture set multiple times."));
	if (!ft_strncmp(line, "EA ", 3) && (game->parsing.step & PARSING_EA))
		return (ft_exit(game, ERR_ARGS, "East texture set multiple times."));
	if (!ft_strncmp(line, "E ", 2) && (game->parsing.step & PARSING_E))
		return (ft_exit(game, ERR_ARGS, "Enemy texture set multiple times."));
	if (!ft_strncmp(line, "D ", 2) && (game->parsing.step & PARSING_D))
		return (ft_exit(game, ERR_ARGS, "Door texture set multiple times."));
	if (!ft_strncmp(line, "F ", 2) && (game->parsing.step & PARSING_F))
		return (ft_exit(game, ERR_ARGS, "Floor color set multiple times."));
	if (!ft_strncmp(line, "C ", 2) && (game->parsing.step & PARSING_C))
		return (ft_exit(game, ERR_ARGS, "Ceiling color set multiple times."));
	return (ft_exit(game, ERR_ARGS, "Element missing or invalid."));
}

int	ft_parsing_line(t_game *game, char *line)
{
	if (*line == '\n' && !(game->parsing.step & PARSING_MAP))
		return (1);
	if ((!ft_strncmp(line, "NO ", 3) && !(game->parsing.step & PARSING_NO))
		|| (!ft_strncmp(line, "SO ", 3) && !(game->parsing.step & PARSING_SO))
		|| (!ft_strncmp(line, "WE ", 3) && !(game->parsing.step & PARSING_WE))
		|| (!ft_strncmp(line, "EA ", 3) && !(game->parsing.step & PARSING_EA))
		|| (!ft_strncmp(line, "E ", 2) && !(game->parsing.step & PARSING_E))
		|| (!ft_strncmp(line, "D ", 2) && !(game->parsing.step & PARSING_D)))
		return (ft_parsing_texture(game, line));
	if ((!ft_strncmp(line, "F ", 2) && !(game->parsing.step & PARSING_F))
		|| (!ft_strncmp(line, "C ", 2) && !(game->parsing.step & PARSING_C)))
		return (ft_parsing_color(game, line));
	if (!game->parsing.succes && *line == '\n' \
		&& (game->parsing.step & PARSING_MAP))
		return (ft_exit(game, ERR_MAP, "Map is not valid."));
	if ((game->parsing.step & PARSING_MAP) \
				|| (!(game->parsing.step & PARSING_MAP) && *line
			&& ((game->parsing.step & PARSING_NO)
				&& (game->parsing.step & PARSING_SO)
				&& (game->parsing.step & PARSING_WE)
				&& (game->parsing.step & PARSING_EA)
				&& (game->parsing.step & PARSING_F)
				&& (game->parsing.step & PARSING_C))))
		return (ft_parsing_map(game, line));
	return (ft_parsing_error(game, line));
}
