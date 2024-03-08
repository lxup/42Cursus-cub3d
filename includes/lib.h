/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:59:16 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/08 11:36:48 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# ifdef __APPLE__
#  include "../mlx-opengl/mlx.h"
#  define OS "macos"
# elif __linux__
#  include "../mlx-linux/mlx.h"
#  define OS "linux"
# endif
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>

#endif