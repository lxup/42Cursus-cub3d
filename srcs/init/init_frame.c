/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:36:07 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 19:40:28 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_frame(t_frame *frame)
{
	ft_init_coord(&frame->ray_dir, 0, 0);
	ft_init_vector(&frame->map, 0, 0);
	ft_init_coord(&frame->side_dist, 0, 0);
	ft_init_coord(&frame->delta_dist, 0, 0);
	ft_init_vector(&frame->step, 0, 0);
	ft_init_coord(&frame->wall, 0, 0);
	frame->hit = 0;
	frame->hit_value = 0;
	frame->side = -1;
	frame->perp_wall_dist = 0;
	frame->line_height = 0;
	frame->draw_start = 0;
	frame->draw_end = 0;
	frame->color = 0;
	return (1);
}
