/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:35:22 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/08 12:36:53 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/* Fonts */
# define F_BOLD "\1\033[1m\2" /* - Bold font */
# define F_UNDERLINE "\1\033[4m\2" /* - Underline font */
# define F_BLINK "\1\033[5m\2" /* - Blink font */
# define F_REVERSE "\1\033[7m\2" /* - Reverse font */
# define F_CONCEAL "\1\033[8m\2" /* - Conceal font */
# define F_RESET "\1\033[0m\2" /* - Reset font */

/* Colors */
# define C_BLACK "\1\033[30m\2" /* - Black color */
# define C_RED "\1\033[31m\2" /* - Red color */
# define C_GREEN "\1\033[32m\2" /* - Green color */
# define C_YELLOW "\1\033[33m\2" /* - Yellow color */
# define C_BLUE "\1\033[34m\2" /* Blue - color */
# define C_MAGENTA "\1\033[35m\2" /* - Magenta color */
# define C_CYAN "\1\033[36m\2" /* - Cyan color */
# define C_WHITE "\1\033[37m\2" /* - White color */
# define C_GRAY "\1\033[90m\2" /* - Gray color */
# define C_LIGHT_GRAY "\1\033[37m\2" /* - Light gray color */
# define C_BEIGE "\1\033[93m\2" /* - Beige color */
# define C_END "\1\033[0m\2"
# define C_RESET "\1\033[0m\2" /* - Reset color */

/* Backgrounds */
# define BG_BLACK "\1\033[40m\2" /* - Black background */
# define BG_RED "\1\033[41m\2" /* - Red background */
# define BG_GREEN "\1\033[42m\2" /* - Green background */
# define BG_YELLOW "\1\033[43m\2" /* - Yellow background */
# define BG_BLUE "\1\033[44m\2" /* - Blue background */
# define BG_MAGENTA "\1\033[45m\2" /* - Magenta background */
# define BG_CYAN "\1\033[46m\2" /* - Cyan background */
# define BG_WHITE "\1\033[47m\2" /* - White background */
# define BG_TRANSPARENT "\1\033[49m\2" /* - Transparent background */

#endif