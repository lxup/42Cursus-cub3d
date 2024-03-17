/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:37:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 16:36:41 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parsing_line(t_game *game, char *line)
{
	// printf("line = %s\n", line);
	// if (!ft_strncmp(line, "R ", 2) && !(game->parsing & PARSING_R))
	// 	return (ft_parsing_resolution(game, line));
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "S ", 2))
		return (ft_parsing_texture(game, line));
	if ((!ft_strncmp(line, "F ", 2) && !(game->parsing & PARSING_F))
		|| (!ft_strncmp(line, "C ", 2) && !(game->parsing & PARSING_C)))
		return (ft_parsing_color(game, line));
	// check line for map
	if ((game->parsing & PARSING_MAP) && (*line == '\n'))
		return (ft_exit(game, ERR_MAP, "Map is not valid."));
	if (game->parsing & PARSING_MAP)
		return (ft_parsing_map(game, line));
	return (ft_parsing_error(game, line));
// 	// Cases
// 	// 1. Resolution
// 	// 2. Texture
// 		// 2.1. North
// 		// 2.2. South
// 		// 2.3. West
// 		// 2.4. East
// 	if (!ft_strncmp(line, "S ", 2) || !ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
// 		return (ft_parsing_texture(game, line));
// 	// 3. Color
// 		// 3.1. Floor
// 		// 3.2. Ceiling
// 	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
// 		return (ft_parsing_color(game, line));
// 	// 4. Map
// 		// 4.1. Check if the line is valid:
// 			// 4.1.1. Check if the line is empty
// 			// 4.1.2. Check if the line is valid
// 		// 4.2. Add the line to the map
// 	// 5. Bonus
// 	// 6. Error
}
