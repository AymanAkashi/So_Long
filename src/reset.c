/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:23:24 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/20 09:04:00 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	game->moves = 0;
	game->collect = game->og_collect;
	return (0);
}
