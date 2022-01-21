/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 02:52:21 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 06:05:59 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_char(char c)
{
	if (c == 'P' || c == 'E' || c == 'H' || c == 'V'
		|| c == 'C' || c == '0' || c == '1' || c == '\n')
		return (1);
	return (0);
}

int	check_player(char **str)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

int	check_exit(char **str)
{
	int	i;
	int	j;
	int	exit;

	exit = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	return (exit);
}

int	check_collect(char **str)
{
	int	i;
	int	j;
	int	collect;

	collect = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	return (collect);
}

void	check_one(char **str)
{
	if (check_collect(str) == 0)
		ft_exit_ps("No Collectible in the Map", 1);
	if (check_player(str) != 1)
		ft_exit_ps("you need one player in the map!", 1);
	if (check_exit(str) == 0)
		ft_exit_ps("No Exit in the Map!", 1);
}
