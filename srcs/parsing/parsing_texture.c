/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:41:03 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 16:35:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_xpm(t_game *game, char *path, t_image *img)
{
	img->img = mlx_xpm_file_to_image(game->win.mlx_ptr, path, &img->size.x, &img->size.y);
	if (img->img == NULL)
		ft_exit(game, ERR_FILE, "Can't open the texture file.");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	if (img->addr == NULL)
		ft_exit(game, ERR_FILE, "Can't get the texture data.");
	return (1);
}

static int	load_texture(t_game *game, char *path, t_image *img, int parsing)
{
	int	fd;

	while (*path == ' ')
		path++;
	if (*path == '\0')
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit(game, ERR_FILE, "Can't open the texture file.");
	if (close(fd) < 0)
		ft_exit(game, ERR_FILE, "Can't close the texture file.");
	load_xpm(game, path, img);
	if (parsing != 0)
		game->parsing |= parsing;
	return (1);
}

int	ft_parsing_texture(t_game *game, char *buffer)
{
	if (!ft_strncmp(buffer, "NO ", 3) && !(game->parsing & PARSING_NO))
		return (load_texture(game, buffer + 2, &game->textures.wall_no, PARSING_NO));
	else if (!ft_strncmp(buffer, "SO ", 3) && !(game->parsing & PARSING_SO))
		return (load_texture(game, buffer + 2, &game->textures.wall_so, PARSING_SO));
	else if (!ft_strncmp(buffer, "WE ", 3) && !(game->parsing & PARSING_WE))
		return (load_texture(game, buffer + 2, &game->textures.wall_we, PARSING_WE));
	else if (!ft_strncmp(buffer, "EA ", 3) && !(game->parsing & PARSING_EA))
		return (load_texture(game, buffer + 2, &game->textures.wall_ea, PARSING_EA));
	else if (!ft_strncmp(buffer, "S ", 2) && !(game->parsing & PARSING_S))
		return (load_texture(game, buffer + 1, &game->textures.sprite, PARSING_S));
	return (0);
}