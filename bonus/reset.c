/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:23:24 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/19 14:57:10 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	reset_enemy(t_enemy *enemy)
{
	if (enemy == NULL)
		return ;
	while (TRUE)
	{
		enemy->tile = enemy->og_tile;
		enemy->dir = 0;
		if (enemy->next == NULL)
			break ;
		enemy = enemy->next;
	}
}

int	reset(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->filemap[y] != NULL)
	{
		x = 0;
		while (game->filemap[y][x].type != 0)
		{
			game->filemap[y][x].type = game->filemap[y][x].or_type;
			if (game->filemap[y][x].type == Player)
				game->player.tile = &game->filemap[y][x];
			x++;
		}
		y++;
	}
	reset_enemy(game->enemy);
	game->moves = 0;
	game->collect = game->og_collect;
	return (0);
}
