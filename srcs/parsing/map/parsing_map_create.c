/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:37:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 11:50:18 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parsing_map_create(t_game *game)
{
	int		i;
	int		height;
	t_list	*current;

	height = ft_lstsize(game->map.content_list);
	game->map.content = ft_calloc(height + 1, sizeof(char *));
	if (game->map.content == NULL)
		return (ft_exit(game, ERR_MAP, "Malloc failed"));
	current = game->map.content_list;
	i = 0;
	while (current && i < height)
	{
		game->map.content[i++] = current->content;
		current = current->next;
	}
	ft_lstclear(&game->map.content_list, NULL);
	game->map.content_list = NULL;
	return (1);
}
