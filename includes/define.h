/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:03:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/20 20:12:27 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifdef __APPLE__
#  define OS "macos"
# elif __linux__
#  define OS "linux"
# endif

/* ************************************************************************** */
/*                                    ERROR                                   */
/* ************************************************************************** */

/* Error values */
typedef enum e_error
{
	ERR_ARGS = 1,
	ERR_MAP,
	ERR_MALLOC,
	ERR_MLX,
	ERR_FILE,
	ERR_TEXTURE,
	ERR_PLAYER,
	ERR_EXIT,
	ERR_COINS,
	ERR_ENEMY,
	ERR_WEAPON,
	ERR_IMG,
	ERR_KEY,
	ERR_EXIT_GAME
}	t_error;

/* ************************************************************************** */
/*                                GAME SETTINGS                               */
/* ************************************************************************** */

# define WINDOW_TITLE 		"cub3d"
# define LIFE_COUNT			4

/* ************************************************************************** */
/*                                MAP SETTINGS                                */
/* ************************************************************************** */

# define FILE_EXTENSION 	".cub"

# define WALL 				'1'
# define EMPTY 				'0'

/* ************************************************************************** */
/*                                    ASSETS                                  */
/* ************************************************************************** */

# define WALL_XPM 			"./assets/water/water_1.xpm"
# define FLOOR_XPM 			"./assets/floor/floor_1.xpm"
# define COINS_XPM 			"./assets/coins/coin_w_bg_00.xpm"
# define EXIT_OPEN_XPM 		"./assets/exit/exit_open.xpm"
# define EXIT_CLOSED_XPM 	"./assets/exit/exit_closed.xpm"
# define HEART_FULL_XPM 	"./assets/heart/heart_full.xpm"
# define HEART_EMPTY_XPM 	"./assets/heart/heart_empty.xpm"
# define PLAYER_FRONT_XPM 	"./assets/chars/fox/fox_front_idle_w_bg_00.xpm"
# define PLAYER_BACK_XPM 	"./assets/chars/fox/fox_back_idle_w_bg_00.xpm"
# define PLAYER_LEFT_XPM 	"./assets/chars/fox/fox_left_idle_w_bg_00.xpm"
# define PLAYER_RIGHT_XPM 	"./assets/chars/fox/fox_right_idle_w_bg_00.xpm"
# define ENEMY_FRONT_XPM 	"./assets/chars/crab/crab_front_idle_w_bg_00.xpm"
# define WEAPON_AXE_XPM 	"./assets/weapons/axe/axe_w_bg_00.xpm"

/* ************************************************************************** */
/*                                     KEY                                    */
/* ************************************************************************** */

# ifdef __APPLE__
#  define KEY_ESC			53
#  define KEY_Q				12
#  define KEY_W				13
#  define KEY_E				14
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_ARROW_TOP		126
#  define KEY_ARROW_BOT		125
#  define KEY_ARROW_LEFT	123
#  define KEY_ARROW_RIGHT	124
# elif __linux__
#  define KEY_ESC			65307
#  define KEY_Q				113
#  define KEY_W				119
#  define KEY_E				101
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
#  define KEY_ARROW_TOP		65362
#  define KEY_ARROW_BOT		65364
#  define KEY_ARROW_LEFT	65361
#  define KEY_ARROW_RIGHT	65363
# endif

/* ************************************************************************** */
/*                                   MOVE	                                  */
/* ************************************************************************** */

// Physical movement
#  define M_UP				1
#  define M_DOWN			2
#  define M_LEFT			3
#  define M_RIGHT			4

// View movement
#  define M_VIEW_UP			5
#  define M_VIEW_DOWN		6
#  define M_VIEW_LEFT		7
#  define M_VIEW_RIGHT		8

/* ************************************************************************** */
/*                                  TEMPLATE                                  */
/* ************************************************************************** */

#endif