/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:30:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 16:41:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_contains_char("NSEW", line[i]))
		{
			if (game->map.spawn.x != -1)
				return (ft_exit(game, ERR_MAP, "Multiple spawn point."));
			game->map.spawn.x = i;
			game->map.spawn.y = game->map.size.y;
		}
		else if (!ft_contains_char(" 01D", line[i]))
			return (ft_exit(game, ERR_MAP, "Invalid character in the map."));
		i++;
	}
	return (1);
}

static int	add_node_map(t_game *game, char *line)
{
	char	*tmp;
	t_list	*new;

	tmp = ft_strdup(line);
	if (!tmp)
		return (ft_exit(game, ERR_MALLOC, "Can't allocate memory."));
	new = ft_lstnew(tmp);
	if (!new)
		return (ft_exit(game, ERR_MALLOC, "Can't allocate memory."));
	ft_lstadd_back(&game->map.content_list, new);
	return (1);
}

int	ft_parsing_map(t_game *game, char *line)
{
	line[ft_strlen(line) - 1] = 0;
	check_map_line(game, line);
	add_node_map(game, line);
	game->parsing.step |= PARSING_MAP;
	if (game->map.size.y == -1)
		game->map.size.y = 0;
	game->map.size.y++;
	if ((int)ft_strlen(line) > game->map.size.x)
		game->map.size.x = (int)ft_strlen(line);
	return (1);
}
