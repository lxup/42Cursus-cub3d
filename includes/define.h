/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:03:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/08 11:31:24 by lquehec          ###   ########.fr       */
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
/*                                GAME SETTINGS                               */
/* ************************************************************************** */

# define WINDOW_TITLE 		"cub3d"
# define LIFE_COUNT			4

/* Others */
# define DIRECTION_TOP		1
# define DIRECTION_BOT		2
# define DIRECTION_LEFT		3
# define DIRECTION_RIGHT	4

/* ************************************************************************** */
/*                                MAP SETTINGS                                */
/* ************************************************************************** */

# define FILE_EXTENSION 	".ber"

# define WALL 				'1'
# define FLOOR 				'0'
# define COINS 				'C'
# define PLAYER 			'P'
# define EXIT 				'E'
# define ENEMY 				'K'
# define WEAPON 			'W'

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
/*                                    IMG                                     */
/* ************************************************************************** */

# define IMG_WIDTH			32
# define IMG_HEIGHT			32

/* ************************************************************************** */
/*                                  TEMPLATE                                  */
/* ************************************************************************** */

#endif