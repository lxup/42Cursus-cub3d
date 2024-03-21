/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_screen_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:04:23 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 22:30:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <ApplicationServices/ApplicationServices.h>

int	custom_mlx_get_screen_size(void *mlx_ptr, int *width, int *height)
{
	CGRect mainScreenRect;
	
	(void)mlx_ptr;
	mainScreenRect = CGDisplayBounds(CGMainDisplayID());
	*width = (int)CGRectGetWidth(mainScreenRect);
    *height = (int)CGRectGetHeight(mainScreenRect);
	return (0);
}
