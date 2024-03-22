/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:58:31 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:55:35 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_next_square(t_game *game)
{
	if (game->frame.side_dist.x < game->frame.side_dist.y)
	{
		game->frame.side_dist.x += game->frame.delta_dist.x;
		game->frame.map.x += game->frame.step.x;
		game->frame.side = 0;
	}
	else
	{
		game->frame.side_dist.y += game->frame.delta_dist.y;
		game->frame.map.y += game->frame.step.y;
		game->frame.side = 1;
	}
	return (1);
}

static int	get_hit_value(t_game *game)
{
	if ((game->frame.step.x < 0 && game->frame.map.x < 0) \
		|| (game->frame.step.y < 0 && game->frame.map.y < 0) \
		|| ((game->frame.map.x >= game->map.size.x) && game->frame.step.x >= 0)
		|| ((game->frame.map.y >= game->map.size.y) && game->frame.step.y >= 0))
	{
		game->frame.hit = 1;
	}
	else if (game->frame.map.x >= 0 && game->frame.map.y >= 0
		&& game->frame.map.x < game->map.size.x \
			&& game->frame.map.y < game->map.size.y)
		game->frame.hit_value = \
			game->map.content[game->frame.map.y][game->frame.map.x];
	return (1);
}

static int	check_hit(t_game *game)
{
	if (game->frame.hit_value == '1')
		game->frame.hit = 1;
	else if (game->frame.hit_value == 'D')
	{
		game->frame.hit = 1;
		game->frame.hit_value = 'D';
	}
	else if (game->frame.hit_value == '0')
		game->frame.hit = 0;
	return (1);
}

int	ft_raycasting_dda(t_game *game)
{
	while (game->frame.hit == 0)
	{
		get_next_square(game);
		get_hit_value(game);
		if (game->frame.hit_value != '0')
			check_hit(game);
	}
	return (1);
}
