/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:41:57 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/02/09 11:51:01 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//initalisation of windows & config DestroyNotify
void	game_init(t_game *game)
{

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_size.x + IMAGE_SIZE / 2,
			game->win_size.y, "So_Long");
	mlx_hook(game->win, 17, 0, end_game, game);
	open_img(game);
}
