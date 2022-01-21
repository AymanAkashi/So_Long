/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:26:01 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 05:22:15 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_enemy_to(t_enemy *enemy, t_type *tile)
{
	static int	z;

	if (z == SPEED)
	{
		enemy->tile->type = Empty;
		tile->type = Enemy;
		enemy->tile = tile;
		z = 0;
	}
	z++;
}

int	change_dir(int dir)
{
	if (dir == 0)
		dir = 1;
	else
		dir = 0;
	return (dir);
}

void	move_her(t_game *effect, t_enemy *enemy)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->left->type == Empty)
			move_enemy_to(enemy, enemy->tile->left);
		else if (enemy->tile->left->type == Player)
		{
			move_enemy_to(enemy, enemy->tile->left);
			end_game_2(effect);
		}
		else
			enemy->dir = change_dir(enemy->dir);
	}
	if (enemy->dir == 1)
	{
		if (enemy->tile->right->type == Empty)
			move_enemy_to(enemy, enemy->tile->right);
		else if (enemy->tile->right->type == Player)
		{
			move_enemy_to(enemy, enemy->tile->right);
			end_game_2(effect);
		}
		else
			enemy->dir = change_dir(enemy->dir);
	}
}

void	move_vec(t_game *effect, t_enemy *enemy)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == Empty)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == Player)
		{
			move_enemy_to(enemy, enemy->tile->up);
			end_game_2(effect);
		}
		else
			enemy->dir = change_dir(enemy->dir);
	}
	if (enemy->dir == 1)
	{
		if (enemy->tile->down->type == Empty)
			move_enemy_to(enemy, enemy->tile->down);
		else if (enemy->tile->down->type == Player)
		{
			move_enemy_to(enemy, enemy->tile->down);
			end_game_2(effect);
		}
		else
			enemy->dir = change_dir(enemy->dir);
	}
}

int	enemy_move(t_game *effect)
{
	t_enemy	*enemy;

	enemy = effect->enemy;
	while (TRUE)
	{
		if (enemy->type == Herozentall)
			move_her(effect, enemy);
		if (enemy->type == Verticall)
			move_vec(effect, enemy);
		if (enemy->next == NULL)
			break ;
		enemy = enemy->next;
	}
	return (0);
}
