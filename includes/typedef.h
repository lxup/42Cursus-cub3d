/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/21 12:05:31 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct	s_coord
{
	double		x;
	double		y;
}	t_coord;

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
	t_image		img;
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

typedef struct	s_frame
{
	t_coord		ray_dir;
	t_vector	map;
	t_coord		side_dist;
	t_coord		delta_dist;
	t_coord		camera;
	t_vector	step;
	t_coord		wall;
	t_vector	mouse;
	int			hit;
	char		hit_value;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
}	t_frame;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	int			move;
	double		speed;
	double		rot_speed;
}	t_player;

typedef struct	s_settings
{
	double		fov;
	double		move_speed;
	double		rot_speed;
}	t_settings;

typedef struct		s_game
{
	t_win			win;
	t_map			map;
	t_textures		textures;
	t_parsing		parsing;
	t_frame			frame;
	t_player		player;
	t_settings		settings;
}	t_game;

#endif