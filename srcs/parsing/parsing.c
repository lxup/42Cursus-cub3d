/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:24:26 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/15 19:37:44 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_parsing_open_fd(t_game *game)
{
	int		len;

	len = ft_strlen(game->map.path);
	if (len < 4 || ft_strncmp(game->map.path + len - 4, FILE_EXTENSION, ft_strlen(FILE_EXTENSION)))
		ft_exit(game, ERR_ARGS, "Invalid file extension, need a .cub file.");
	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
		ft_exit(game, ERR_FILE, "Can't open the file.");
	return (game->map.fd);
}

static int	ft_parsing_get_map(t_game *game)
{
	char	*buffer;

	buffer = ft_strdup("");
	if (!buffer)
		ft_exit(game, ERR_MALLOC, "Malloc failed.");
	while (1)
	{
		buffer = get_next_line(game->map.fd);
		if (!buffer || !*buffer)
		{
			if (buffer)
				free(buffer);
			break ;
		}
		ft_parsing_line(game, buffer);
		free(buffer);
	}
	if (close(game->map.fd) < 0)
		ft_exit(game, ERR_FILE, "Can't close the file.");
	return (1);
}

int	ft_parsing(t_game *game)
{
	ft_parsing_open_fd(game);
	ft_parsing_get_map(game);
	return (1);
}