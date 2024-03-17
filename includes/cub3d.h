/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:43:05 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/17 15:52:57 by lquehec          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

int		ft_init(t_game *game, char *file);
int		ft_init_win(t_game *game);
int		ft_init_map(t_game *game, char *file);
int		ft_init_texture(t_game *game);

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */

int		ft_parsing(t_game *game);
int		ft_parsing_get_map(t_game *game);
int		ft_parsing_line(t_game *game, char *line);
int		ft_parsing_texture(t_game *game, char *buffer);
int		ft_parsing_color(t_game *game, char *line);
int		ft_parsing_map(t_game *game, char *line);
int		ft_parsing_error(t_game *game, char *line);

/* ************************************************************************** */
/*                                    EXIT                                    */
/* ************************************************************************** */

int		ft_exit(t_game *game, t_error error, char *msg);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

void	ft_2d_free(char **array);
int		ft_2d_putstr(char **array);
int		ft_2d_strlen(char **array);
#endif
