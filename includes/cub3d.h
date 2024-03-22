/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:43:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 18:06:26 by lquehec          ###   ########.fr       */
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
int		ft_init_game(t_game *game);
int		ft_init_player(t_game *game);

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

/* ************************************************************************** */
/*                                   HOOKS                                    */
/* ************************************************************************** */

int		ft_hooks(t_game *game);
int		ft_hook_on_window_close(t_game *game);
int		ft_hook_on_keypress(int keycode, t_game *game);
int		ft_hook_on_keyrelease(int keycode, t_game *game);
int		ft_hook_on_mousemove(int x, int y, t_game *game);
int		ft_hook_on_mousepress(int button, int x, int y, t_game *game);
int		ft_hook_on_mouserelease(int button, int x, int y, t_game *game);

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
int		ft_raycasting_draw_floor(t_game *game, int x);
int		ft_raycasting_draw_ceiling(t_game *game, int x);

/* ************************************************************************** */
/*                                   BONUS                                    */
/* ************************************************************************** */

int		ft_minimap(t_game *game);
int		ft_minimap_draw(t_game *game, t_vector map_pos, t_vector map_size);
int		ft_minimap_widget(t_game *game, t_vector map_pos, t_vector map_size);

/* ************************************************************************** */
/*                                   PLAYER                                   */
/* ************************************************************************** */

int		ft_move_player(t_game *game, t_player *player);
int		ft_move_player_view_left(t_game *game, t_player *player);
int		ft_move_player_view_right(t_game *game, t_player *player);
int		ft_move_player_view_up(t_player *player);
int		ft_move_player_view_down(t_player *player);
int		ft_move_collision(t_game *game, t_player *player, double speed, \
			int move);

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
int		custom_mlx_get_screen_size(void *mlx_ptr, int *width, int *height);
int		custom_mlx_destroy_display(void *mlx_ptr);
int		custom_mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
int		custom_mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
int		custom_mlx_draw_square(t_image *img, t_vector start, t_vector end, \
			int color);
int		custom_mlx_draw_circle(t_image *img, t_coord origin, int radius, \
			int color);
int		custom_mlx_draw_line(t_image *img, t_coord start, t_coord end, \
			int color);
int		custom_mlx_get_pixel_color(t_image *img, int x, int y);

#endif
