/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:51:29 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 04:40:14 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_enemies(t_game *game)
{
	remove_player(game);
	end_game_2(game);
}

t_enemy	*new_enemy(t_type *tile, t_enemy_type c)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		ft_exit_ps("malloc error on new_enemy()", 1);
	enemy->type = c;
	enemy->dir = 0;
	enemy->tile = tile;
	enemy->count++;
	enemy->og_tile = enemy->tile;
	enemy->next = NULL;
	return (enemy);
}

t_enemy	*last_enemy(t_enemy *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_lst_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	add_enemy(t_game *game, t_type *tile, t_enemy_type c)
{
	t_enemy	*new;

	new = new_enemy(tile, c);
	if (new == NULL)
		return ;
	if (game->enemy == NULL)
		game->enemy = new;
	else
		ft_lst_back(&game->enemy, new);
}
