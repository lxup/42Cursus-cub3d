/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:24:26 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:49:08 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_parsing_open_fd(t_game *game)
{
	int		len;

	len = ft_strlen(game->map.path);
	if (len < 4 || ft_strncmp(game->map.path + len - 4, FILE_EXTENSION, \
		ft_strlen(FILE_EXTENSION)))
		ft_exit(game, ERR_ARGS, "Invalid file extension, need a .cub file.");
	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
		ft_exit(game, ERR_FILE, "Can't open the file.");
	return (game->map.fd);
}

static int	ft_parsing_get_map(t_game *game)
{
	while (1)
	{
		game->parsing.line = get_next_line(game->map.fd);
		if (!game->parsing.line || !*game->parsing.line)
			break ;
		ft_parsing_line(game, game->parsing.line);
		free(game->parsing.line);
		game->parsing.line = NULL;
	}
	if (close(game->map.fd) < 0)
		ft_exit(game, ERR_FILE, "Can't close the file.");
	game->map.fd = -1;
	return (1);
}

int	ft_parsing(t_game *game)
{
	ft_parsing_open_fd(game);
	ft_parsing_get_map(game);
	ft_parsing_map_check(game);
	return (1);
}
