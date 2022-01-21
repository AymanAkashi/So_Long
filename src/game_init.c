/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:41:57 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/20 09:01:23 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_init(t_game *game)
{
	int	i;
	int	j;

	j = game->win_size.x / 2;
	i = game->win_size.y / 2;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_size.x + IMAGE_SIZE / 2,
			game->win_size.y, "So_Long");
	mlx_hook(game->win, 17, 0, end_game, game);
	open_img(game);
}
