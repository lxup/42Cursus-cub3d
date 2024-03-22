/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:03:40 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:35:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_parsing(t_game *game)
{
	if (game->parsing.line)
	{
		free(game->parsing.line);
		game->parsing.line = NULL;
	}
	return (1);
}
