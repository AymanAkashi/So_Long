/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:04:48 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/18 17:28:53 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_check	define_num(char c)
{
	if (c == '1')
		return (Wall);
	if (c == 'P')
		return (Player);
	if (c == 'E')
		return (Exit);
	if (c == 'C')
		return (Collect);
	return (Empty);
}

void	gen_tile(t_type *tile, t_game *game)
{
	if (tile->type == Player)
			game->player.tile = tile;
	else if (tile->type == Collect)
		game->collect++;
}

void	set_map(t_type **tilemap, int x, int y)
{
	tilemap[y][x].or_type = tilemap[y][x].type;
	tilemap[y][x].verct.x = x * IMAGE_SIZE;
	tilemap[y][x].verct.y = y * IMAGE_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
			tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

t_type	**alloca_type(char **map)
{
	int		i;
	t_type	**tilemap;

	i = 0;
	tilemap = (t_type **)malloc(sizeof(t_type *) * counter_y(map) + 1);
	while (map[i])
	{
		tilemap[i] = (t_type *)malloc(sizeof(t_type) * ft_strlen(map[i]) + 1);
		if (!tilemap)
		{
			free(tilemap);
			return (0);
		}
		i++;
	}
	tilemap[i] = NULL;
	return (tilemap);
}

t_type	**gen_map(char **map, t_game *game)
{
	t_type	**tilemap;
	int		x;
	int		y;

	tilemap = alloca_type(map);
	if (tilemap == NULL)
		return (NULL);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			tilemap[y][x].type = define_num(map[y][x]);
			set_map(tilemap, x, y);
			gen_tile(&tilemap[y][x], game);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	game->win_size.x = x * IMAGE_SIZE;
	game->win_size.y = y * IMAGE_SIZE;
	return (tilemap);
}
