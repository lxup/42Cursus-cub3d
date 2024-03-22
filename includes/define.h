/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:03:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:35:09 by lquehec          ###   ########.fr       */
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
# define MAX_WIDTH			1920
# define MAX_HEIGHT			1080

/* ************************************************************************** */
/*                                MAP SETTINGS                                */
/* ************************************************************************** */

# define FILE_EXTENSION 	".cub"

# define WALL 				'1'
# define EMPTY 				'0'

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */

# define PARSING_NO			0x00001
# define PARSING_SO			0x00002
# define PARSING_WE			0x00004
# define PARSING_EA			0x00008
# define PARSING_E			0x00010
# define PARSING_D			0x00020
# define PARSING_F			0x00040
# define PARSING_C			0x00080
# define PARSING_MAP		0x00100

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
#  define KEY_M				41
#  define KEY_ARROW_TOP		126
#  define KEY_ARROW_BOT		125
#  define KEY_ARROW_LEFT	123
#  define KEY_ARROW_RIGHT	124
#  define KEY_SHIFT			257
#  define KEY_CTRL			256
#  define KEY_TAB			48
# elif __linux__
#  define KEY_ESC			65307
#  define KEY_Q				113
#  define KEY_W				119
#  define KEY_E				101
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
#  define KEY_M				109
#  define KEY_ARROW_TOP		65362
#  define KEY_ARROW_BOT		65364
#  define KEY_ARROW_LEFT	65361
#  define KEY_ARROW_RIGHT	65363
#  define KEY_SHIFT			65505
#  define KEY_CTRL			65507
#  define KEY_TAB			65289
# endif

/* ************************************************************************** */
/*                                   HOOK                                     */
/* ************************************************************************** */

# ifdef __APPLE__
#  define H_KEYPRESS		2
#  define H_KEYRELEASE		3
#  define H_MOUSEMOVE		6
#  define H_EXIT			17
#  define H_MASK_KEYPRESS	0
#  define H_MASK_KEYRELEASE	0
#  define H_MASK_MOUSEMOVE	0
#  define H_MASK_EXIT		0x1
# elif __linux__
#  define H_KEYPRESS		2
#  define H_KEYRELEASE		3
#  define H_MOUSEMOVE		6
#  define H_EXIT			17
#  define H_MASK_KEYPRESS	0x1
#  define H_MASK_KEYRELEASE	0x2
#  define H_MASK_MOUSEMOVE	0x40
#  define H_MASK_EXIT		0
# endif

/* ************************************************************************** */
/*                                   MOVE	                                  */
/* ************************************************************************** */

# define M_UP				0x00001
# define M_DOWN				0x00002
# define M_LEFT				0x00004
# define M_RIGHT			0x00008

# define M_VIEW_UP			0x00010
# define M_VIEW_DOWN		0x00020
# define M_VIEW_LEFT		0x00040
# define M_VIEW_RIGHT		0x00080

# define M_SPRINT			0x00100
# define M_CROUCH			0x00200
# define M_JUMP				0x00400

# define M_MAP				0x00800

/* ************************************************************************** */
/*                                  TEMPLATE                                  */
/* ************************************************************************** */

#endif