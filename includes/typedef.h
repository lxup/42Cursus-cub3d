/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/15 18:26:12 by lquehec          ###   ########.fr       */
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
	t_vector	*size;
	int			fd;
	char		**items;
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

typedef struct		s_game
{
	t_win			win;
	t_map			map;
}	t_game;

#endif