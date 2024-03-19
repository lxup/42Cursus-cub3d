/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/19 18:35:22 by lquehec          ###   ########.fr       */
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
	ft_init(&game, av[1]);
	game.win.mlx_ptr = mlx_init();
	if (!game.win.mlx_ptr)
		ft_exit(&game, ERR_MLX, "Mlx failed to init");
	ft_parsing(&game);
	ft_gameplay(&game);
	return (ft_exit(&game, EXIT_SUCCESS, NULL));
}
