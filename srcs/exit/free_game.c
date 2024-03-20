/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:02:27 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 19:21:16 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_game(t_game *game)
{
	ft_free_map(game);
	ft_free_texture(game);
	ft_free_parsing(game);
	ft_free_win(game);
	return (1);
}
