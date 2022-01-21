/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:57:03 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 04:33:35 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_to_empty(t_game *game, t_type *tile)
{
	tile->type = Player;
	if (game->player.tile->type != Exit)
		game->player.tile->type = Empty;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_type *tile)
{
	tile->type = Player;
	game->player.tile->type = Empty;
	game->player.tile = tile;
	game->collect--;
}

void	move_to_exit(t_game *game)
{
	printf("Moves -> %d\n", ++game->moves);
	blue();
	printf("-------𝚈𝚘𝚞 𝚆𝙸𝚗-------\n");
	reset1();
	remove_player(game);
	game->collect = -1;
	end_game(game);
}

t_bool	move_to(t_game *game, t_type *tile)
{
	if (tile->type == Empty)
		move_to_empty(game, tile);
	else if (tile->type == Collect)
		pick_collect(game, tile);
	else if (tile->type == Exit && game->collect <= 0)
		move_to_exit(game);
	else
		return (FALSE);
	return (TRUE);
}
