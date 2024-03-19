/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:14:33 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 12:04:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_fd(t_game *game)
{
	if (game->map.fd != -1)
	{
		close(game->map.fd);
		game->map.fd = -1;
	}
	return (1);
}

static int	clear_map_list(t_game *game)
{
	if (game->map.content_list)
	{
		ft_lstclear(&game->map.content_list, &free);
		game->map.content_list = NULL;
	}
	return (1);
}

static int	free_content(t_game *game)
{
	if (game->map.content)
	{
		ft_2d_free(game->map.content, -1);
		game->map.content = NULL;
	}
	if (game->map.content_dup)
	{
		ft_2d_free(game->map.content_dup, -1);
		game->map.content_dup = NULL;
	}
	return (1);
}

int	ft_free_map(t_game *game)
{
	free_content(game);
	clear_map_list(game);
	close_fd(game);
	return (1);
}