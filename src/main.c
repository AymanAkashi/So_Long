/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:46:55 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 00:56:10 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

void	free_type(t_type **tilemap)
{
	int		i;

	i = 0;
	while (tilemap[i])
	{
		free(tilemap[i]);
		i++;
	}
	free(tilemap);
}

int	end_game_2(t_game *game)
{
	free_type(game->filemap);
	printf("You Lose\n");
	game->filemap = NULL;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	end_game(t_game *game)
{
	free_filemap(game);
	game->filemap = NULL;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!start_game(ac, av, &game))
		return (0);
	mlx_hook(game.win, 2, 1L << 1, input, (void *)&game);
	mlx_loop_hook(game.mlx, loop, (void *)&game);
	mlx_loop(game.mlx);
}
