/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_screen_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:04:23 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 22:26:23 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_mlx_get_screen_size(void *mlx_ptr, int *width, int *height)
{
	return (mlx_get_screen_size(mlx_ptr, width, height));
}
