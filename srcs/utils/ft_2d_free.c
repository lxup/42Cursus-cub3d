/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:34:46 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 11:58:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_2d_free(char **array, int size)
{
	int	i;

	i = 0;
	if (size != -1)
	{
		while (i < size)
		{
			free(array[i]);
			i++;
		}
	}
	else
	{
		while (array && array[i])
		{
			free(array[i]);
			i++;
		}
	}
	free(array);
}
