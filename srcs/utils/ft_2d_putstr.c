/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:28:01 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 17:41:57 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_2d_putstr(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
	return (i);
}
