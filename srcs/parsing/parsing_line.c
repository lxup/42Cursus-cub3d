/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:37:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/15 19:45:36 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parsing_line(t_game *game, char *buffer)
{
	// Cases
	// 1. Resolution
	// 2. Texture
		// 2.1. North
		// 2.2. South
		// 2.3. West
		// 2.4. East
	// 3. Color
		// 3.1. Floor
		// 3.2. Ceiling
	// 4. Map
		// 4.1. Check if the line is valid:
			// 4.1.1. Check if the line is empty
			// 4.1.2. Check if the line is valid
		// 4.2. Add the line to the map
	// 5. Bonus
	// 6. Error
}
