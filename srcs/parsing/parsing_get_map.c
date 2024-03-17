/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:03:50 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 16:36:27 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_map(t_game *game)
{
	char	*line;

	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line || !*line)
		{
			if (line)
				free(line);
			break ;
		}
		ft_parsing_line(game, line);
		free(line);
	}
	return (1);
}

// static int	build_map(t_game *game, t_list **map)
// {
// 	t_list	*current;
// 	int	size;
// 	int	i;

// 	current = *map;
// 	size = ft_lstsize(*map);
// 	game->map.content = ft_calloc(size + 1, sizeof(char *));
// 	if (!game->map.content)
// 		ft_exit(game, ERR_MALLOC, "Can't allocate memory."); // TODO: close fd
// 	i = 0;
// 	while (current && i < size)
// 	{
// 		game->map.content[i] = current->content;
// 		current = current->next;
// 		i++;
// 	}
// 	// remove node but not content because it's used in game->map.content
// 	ft_lstclear(map, NULL);
// 	*map = NULL; 
// 	return (1);
// }

int	ft_parsing_get_map(t_game *game)
{
	read_map(game);
	// build_map(game, &tmp);
	// ft_2d_putstr(game->map.content);
	if (close(game->map.fd) < 0)
		ft_exit(game, ERR_FILE, "Can't close the file.");
	return (1);
}