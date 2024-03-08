/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:13 by lquehec           #+#    #+#             */
/*   Updated: 2024/03/08 12:41:26 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	errno = 0;
	game = (t_game){0};
	if (ac < 2)
		ft_exit(&game, ERR_ARGS, "U need to specify a map file, dumb ass !");
	else if (ac > 2)
		ft_exit(&game, ERR_ARGS, "Too many arguments, just think...");
	(void)av;
	(void)envp;
	printf("salam\n");
	return (0);
}