/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:43:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 19:40:41 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Includes */
# include "lib.h"
# include "colors.h"
# include "define.h"
# include "typedef.h"

/* ************************************************************************** */
/*                                    CORE                                    */
/* ************************************************************************** */

int		ft_gameplay(t_game *game);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

int		ft_init(t_game *game, char *file);
int		ft_init_win(t_game *game);
int		ft_init_map(t_game *game, char *file);
int		ft_init_texture(t_game *game);
int		ft_init_image(t_game *game, t_image *img);
int		ft_init_vector(t_vector *vec, int x, int y);
int		ft_init_coord(t_coord *coord, double x, double y);
int		ft_init_frame(t_frame *frame);

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */

int		ft_parsing(t_game *game);
int		ft_parsing_line(t_game *game, char *line);
int		ft_parsing_texture(t_game *game, char *buffer);
int		ft_parsing_color(t_game *game, char *line);
int		ft_parsing_map(t_game *game, char *line);
int		ft_parsing_map_check(t_game *game);
int		ft_parsing_map_create(t_game *game);
int		ft_parsing_map_leak(t_game *game, int x, int y);
int		ft_parsing_player(t_game *game);

/* ************************************************************************** */
/*                                   HOOKS                                    */
/* ************************************************************************** */

int		ft_hooks(t_game *game);
int		ft_hook_on_window_close(t_game *game);
int		ft_hook_on_keypress(int keycode, t_game *game);
int		ft_hook_on_keyrelease(int keycode, t_game *game);

/* ************************************************************************** */
/*                                 RAYCASTING                                 */
/* ************************************************************************** */

int		ft_render(t_game *game);
int		ft_raycasting(t_game *game);
void	ft_raycasting_step(t_game *game);
int		ft_raycasting_dda(t_game *game);
int		ft_raycasting_wall(t_game *game);
int		ft_raycasting_draw(t_game *game, int x);
int		ft_raycasting_draw_wall(t_game *game, int x);

/* ************************************************************************** */
/*                                    EXIT                                    */
/* ************************************************************************** */

int		ft_exit(t_game *game, t_error error, char *msg);
int		ft_free_game(t_game *game);
int		ft_free_map(t_game *game);
int		ft_free_parsing(t_game *game);
int		ft_free_texture(t_game *game);
int		ft_free_win(t_game *game);
int		free_image(t_game *game, t_image *img);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

void	ft_2d_free(char **array, int size);
int		ft_2d_putstr(char **array);
int		ft_2d_size(char **array);
char	**ft_2d_dup(char **array);
void	ft_print_color(t_color color);
int		ft_color_to_int(t_color color);
void	ft_print_frame(t_frame frame);

/* ************************************************************************** */
/*                                  MLX (Custom)                              */
/* ************************************************************************** */

int		custom_mlx_pixel_put(t_image *img, int x, int y, int color);

#endif
