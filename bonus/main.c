/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:46:55 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 07:18:07 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

int	end_game_2(t_game *game)
{
	free_enemies(game);
	free_filemap(game);
	red();
	printf("-------𝒀𝒐𝒖 𝑳𝒐𝒔𝒆------\n");
	reset1();
	game->filemap = NULL;
	exit(0);
}

int	end_game(t_game *game)
{
	free_enemies(game);
	free_filemap(game);
	game->filemap = NULL;
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!start_game(ac, av, &game))
		return (0);
	mlx_hook(game.win, 2, 0, input, (void *)&game);
	mlx_loop_hook(game.mlx, loop, (void *)&game);
	mlx_loop(game.mlx);
}
