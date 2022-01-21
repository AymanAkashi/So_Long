/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:47:00 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/20 08:53:48 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_image(t_type tile, t_game game, t_size pos)
{
	if (tile.type == Wall)
		mlx_put_image_to_window(game.mlx, game.win,
			game.wall, pos.x, pos.y);
	else if (tile.type == Exit)
	{
		if (game.collect != 0)
			mlx_put_image_to_window(game.mlx, game.win,
				game.door_close, pos.x, pos.y);
		if (game.collect == 0)
			mlx_put_image_to_window(game.mlx, game.win,
				game.door_open, pos.x, pos.y);
	}
	else if (tile.type == Collect)
		mlx_put_image_to_window(game.mlx, game.win,
			game.collect_img.current_img, pos.x, pos.y);
	else if (tile.type == Player)
		mlx_put_image_to_window(game.mlx, game.win,
			game.player.current_img, pos.x, pos.y);
}

void	render(t_game game)
{
	t_type	tile;
	int		x;
	int		y;

	y = 0;
	mlx_clear_window(game.mlx, game.win);
	while (game.filemap[y] != NULL)
	{
		x = 0;
		while (game.filemap[y][x].type != 0)
		{
			tile = game.filemap[y][x];
			draw_image(tile, game, tile.verct);
			x++;
		}
		y++;
	}
}
