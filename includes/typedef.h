/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 21:42:49 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_vector
{
	int			x;
	int			y;
}	t_vector;


typedef struct s_map
{
	char		*path;
	t_vector	size;
	int			fd;
	char		**content;
	t_list		*content_list;
	t_vector	spawn;
}	t_map;

typedef struct s_image
{
	void		*img;
	char		*addr;
	t_vector	size;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_image;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	t_image		frame;
}	t_win;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}	t_color;

typedef struct s_textures
{
	t_image		wall_no;
	t_image		wall_so;
	t_image		wall_we;
	t_image		wall_ea;
	t_image		sprite;
	t_color		floor;
	t_color		ceiling;
}	t_textures;

typedef struct	s_parsing
{
	char		*line;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
	int			map;
	int			succes;
}	t_parsing;

typedef struct		s_game
{
	t_win			win;
	t_map			map;
	t_textures		textures;
	t_parsing		parsing;
}	t_game;

#endif