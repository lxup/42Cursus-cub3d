/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/22 18:25:20 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_exit_err(t_error error, char *msg)
{
	if (error)
		ft_dprintf(2, C_RED "Error -> %s\n" C_RESET, msg);
	return (exit(error), error);
}

int	main(int ac, char **av)
{
	t_game	game;

	errno = 0;
	if (ac < 2)
		return (ft_exit_err(ERR_ARGS, "U need to specify a map file, "\
			"dumb ass !"));
	else if (ac > 2)
		return (ft_exit_err(ERR_ARGS, "Too many arguments, just think..."));
	ft_init(&game, av[1]);
	game.win.mlx_ptr = mlx_init();
	if (!game.win.mlx_ptr)
		ft_exit(&game, ERR_MLX, "Mlx failed to init");
	ft_parsing(&game);
	ft_gameplay(&game);
	return (ft_exit(&game, EXIT_SUCCESS, NULL));
}
