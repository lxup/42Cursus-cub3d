/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:39:46 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 18:44:33 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_frame(t_frame frame)
{
	printf("\n=== FRAME ===\n");
	printf("ray_dir: %f, %f\n", frame.ray_dir.x, frame.ray_dir.y);
	printf("map: %d, %d\n", frame.map.x, frame.map.y);
	printf("side_dist: %f, %f\n", frame.side_dist.x, frame.side_dist.y);
	printf("delta_dist: %f, %f\n", frame.delta_dist.x, frame.delta_dist.y);
	printf("camera: %f, %f\n", frame.camera.x, frame.camera.y);
	printf("step: %d, %d\n", frame.step.x, frame.step.y);
	printf("hit: %d\n", frame.hit);
	printf("hit_value: %c\n", frame.hit_value);
	printf("side: %d\n", frame.side);
	printf("perp_wall_dist: %f\n", frame.perp_wall_dist);
	printf("line_height: %d\n", frame.line_height);
	printf("draw_start: %d\n", frame.draw_start);
	printf("draw_end: %d\n", frame.draw_end);
	printf("wall: %f, %f\n", frame.wall.x, frame.wall.y);
	printf("color: %d\n", frame.color);
	return ;
}
