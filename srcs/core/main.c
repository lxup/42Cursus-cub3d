/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/15 18:42:08 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	errno = 0;
	if (ac < 2)
		ft_exit(&game, ERR_ARGS, "U need to specify a map file, dumb ass !");
	else if (ac > 2)
		ft_exit(&game, ERR_ARGS, "Too many arguments, just think...");
	ft_memset(&game, 0, sizeof(t_game));
	game.map.path = av[1];
	
	ft_parsing(&game);
	return (0);
}