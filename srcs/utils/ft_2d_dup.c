/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:59:25 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 12:00:14 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_2d_dup(char **array)
{
	char	**dup;
	int		i;

	if (!array)
		return (NULL);
	dup = malloc(sizeof(char *) * (ft_2d_size(array) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (array && array[i])
	{
		dup[i] = ft_strdup(array[i]);
		if (!dup[i])
		{
			ft_2d_free(dup, i);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
