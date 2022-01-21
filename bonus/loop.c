/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:24:26 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 11:58:09 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_game(t_game *game)
{
	game->player.action_frames = 10;
	game->player.ft_frames = 15;
	game->collect_img.frame = 20;
}

int	loop(t_game *game)
{
	if (game->count > 5)
		nature(game);
	player_animation(&game->player, game);
	collec_animation(&game->collect_img);
	if (game->enemy != NULL)
	{
		enemy_animation(game);
		enemy_move(game);
	}
	render(*game);
	return (1);
}
