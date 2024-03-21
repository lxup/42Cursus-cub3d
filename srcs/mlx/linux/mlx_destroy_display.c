/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:21:54 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 22:25:23 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_mlx_destroy_display(void *mlx_ptr)
{
	if (!mlx_ptr)
		return (0);
	return (mlx_destroy_display(mlx_ptr));
}
