/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:40:37 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 15:50:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init(t_game *game, char *file)
{
	ft_memset(game, 0, sizeof(t_game));
	ft_init_win(game);
	ft_init_map(game, file);
	ft_init_texture(game);
	return (1);
}
