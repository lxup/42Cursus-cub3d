/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:25:30 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:44:08 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_string_to_int(char **str)
{
	int	result;

	result = 0;
	if (!*str || !**str)
		return (-1);
	if (**str == ',')
		*str += 1;
	if (!(ft_isdigit(**str)))
		return (-1);
	while (ft_isdigit(**str))
	{
		result *= 10;
		result += **str - 48;
		*str += 1;
	}
	if (result > 255)
		return (-1);
	return (result);
}

int	ft_parsing_color(t_game *game, char *line)
{
	char	*cursor;
	t_color	*color;

	line[ft_strlen(line) - 1] = 0;
	if (!ft_strncmp(line, "F ", 2))
		color = &game->textures.floor;
	else if (!ft_strncmp(line, "C ", 2))
		color = &game->textures.ceiling;
	cursor = line + 2;
	while (*cursor == ' ' || *cursor == '\t')
		cursor++;
	color->r = rgb_string_to_int(&cursor);
	color->g = rgb_string_to_int(&cursor);
	color->b = rgb_string_to_int(&cursor);
	if (color->r < 0 || color->g < 0 || color->b < 0 \
		|| color->r > 255 || color->g > 255 || color->b > 255 \
		|| *cursor != '\0')
		ft_exit(game, ERR_ARGS, "Invalid color.\nSyntax: R,G,B\nR,G,B"\
			" must be between 0 and 255.");
	if (color == &game->textures.floor)
		game->parsing.step |= PARSING_F;
	else
		game->parsing.step |= PARSING_C;
	return (1);
}
