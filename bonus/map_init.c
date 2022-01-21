/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:01:44 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 01:08:12 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_map(char **map)
{
	if (map[0][0] == '\n')
	{
		ft_putstr_fd("First charchter in the map is empty", 1);
		return (0);
	}
	if (is_rect(map) == 0)
	{
		ft_putstr_fd("Wrong Map !\n", 1);
		return (0);
	}
	if (is_wall(map) == 0)
	{
		ft_putstr_fd("Wrong Map !\n", 1);
		return (0);
	}
	check_all(map);
	return (1);
}

t_type	**init_map(char **av, t_game *game)
{
	char	**map;
	t_type	**tilemap;

	map = NULL;
	map = read_map(av[1], map);
	if (map == NULL)
		return (NULL);
	if (!check_map(map))
	{
		free_map(map);
		return (0);
	}
	tilemap = gen_map(map, game);
	free_map(map);
	return (tilemap);
}
