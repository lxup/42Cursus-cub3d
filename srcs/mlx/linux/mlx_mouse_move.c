/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:20:24 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 10:22:25 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y)
{
	return (mlx_mouse_move(mlx_ptr, win_ptr, x, y));
}
