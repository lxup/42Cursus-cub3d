/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 15:49:14 by lquehec          ###   ########.fr       */
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
	int			e_count;
	int			p_count;
	int			c_count;
	int			k_count;
	int			w_count;
	t_vector	spawn;
}	t_map;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
}	t_win;

typedef struct s_image
{
	void		*img;
	char		*addr;
	t_vector	size;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_image;

typedef struct s_textures
{
	t_image		wall_no;
	t_image		wall_so;
	t_image		wall_we;
	t_image		wall_ea;
	t_image		sprite;
	t_image		coins;
	t_image		exit_open;
	t_image		exit_closed;
	t_image		heart_full;
	t_image		heart_empty;
	t_image		enemy;
	t_image		weapon;
}	t_textures;

typedef struct		s_game
{
	t_win			win;
	t_map			map;
	t_textures		textures;
	int				parsing;
}	t_game;

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */

typedef enum e_parsing
{
	PARSING_R = 1,
	PARSING_NO,
	PARSING_SO,
	PARSING_EA,
	PARSING_WE,
	PARSING_S,
	PARSING_F,
	PARSING_C,
	PARSING_MAP,
}	t_parsing;

#endif