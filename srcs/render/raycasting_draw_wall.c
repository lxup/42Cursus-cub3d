/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:26:28 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 19:54:38 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_raycasting_draw_wall_verline(t_game *game, int x, int y)
{
	if (game->frame.side == 0)
	{
		if (game->frame.step.x == 1)
			game->frame.color = 0x00FF0000;
		else
			game->frame.color = 0x000000FF;
	}
	else
	{
		if (game->frame.step.y == 1)
			game->frame.color = 0x00FFFF00;
		else
			game->frame.color = 0x0000FF00;
	}
	while (y < game->frame.draw_end)
	{
		custom_mlx_pixel_put(&game->win.img, x, y, game->frame.color);
		y++;
	}
	return (1);
}

static int	custom_mlx_get_pixel_color(t_image *img, int x, int y)
{
	if (img == NULL || img->size.x == 0 || img->size.y == 0 || img->addr == NULL)
		return (0);
	x = abs(x);
	y = abs(y);
	if (x < 0 || y < 0 || x > img->size.x || y > img->size.y)
		return (0);
	return (*(int *)(img->addr + (((y * img->size.x) + x) * (img->bits_per_pixel / 8))));
}

static t_image	*get_img_src_wall(t_game *game)
{
	if (game->frame.side == 0 && game->frame.ray_dir.x > 0)
		return (&game->textures.wall_no);
	if (game->frame.side == 0 && game->frame.ray_dir.x < 0)
		return (&game->textures.wall_so);
	if (game->frame.side == 1 && game->frame.ray_dir.y > 0)
		return (&game->textures.wall_we);
	if (game->frame.side == 1 && game->frame.ray_dir.y < 0)
		return (&game->textures.wall_ea);
	return (NULL);
}

static t_image	*get_img_src(t_game *game)
{
	if (game->frame.hit_value == '1')
		return (get_img_src_wall(game));
	return (NULL);
}

static int	set_texture(t_game *game, t_texture *texture, t_image *img_src)
{
	texture->step = 1.0 * img_src->size.x / game->frame.line_height;
	texture->pos = (game->frame.draw_start - game->win.height / 2 + game->frame.line_height / 2) * texture->step;
	texture->tex.x = (int)game->frame.wall.x * (double)img_src->size.x;
	if (game->frame.side == 0 && game->frame.ray_dir.x > 0)
		texture->tex.x = img_src->size.x - texture->tex.x - 1;
	if (game->frame.side == 1 && game->frame.ray_dir.y < 0)
		texture->tex.x = img_src->size.x - texture->tex.x - 1;
	return (1);
}

int	ft_raycasting_draw_wall(t_game *game, int x)
{
	t_image		*img_src;
	t_texture	texture;
	
	img_src = get_img_src(game);
	if (img_src == NULL)
		return (ft_raycasting_draw_wall_verline(game, x, game->frame.draw_start));
	set_texture(game, &texture, img_src);
	while (game->frame.draw_start <= game->frame.draw_end)
	{
		texture.tex.y = (int)texture.pos;
		texture.pos += texture.step;
		texture.color = custom_mlx_get_pixel_color(img_src, texture.tex.x, texture.tex.y);
		custom_mlx_pixel_put(&game->win.img, x, game->frame.draw_start, texture.color);
		game->frame.draw_start++;
	}
	return (1);
}