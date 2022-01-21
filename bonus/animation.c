/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:21:26 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/19 14:56:17 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	player_animation(t_player *player, t_game *game)
{
	static int	imgs;

	if (imgs == 3)
	{
		imgs = 0;
		game->player.ft_frames = 15;
	}
	if (game->player.ft_frames == 0)
	{
		game->player.ft_frames = 15;
		imgs++;
	}
	if (imgs == 0)
		player->current_img = player->ft_img_0;
	else if (imgs == 1)
		player->current_img = player->ft_img_1;
	else if (imgs == 2)
		player->current_img = player->ft_img_2;
	game->player.ft_frames--;
	game->count++;
}

void	collec_animation(t_collect *collect)
{
	static int	imgs;

	if (imgs == 3)
	{
		imgs = 0;
		collect->frame = 20;
	}
	if (collect->frame == 0)
	{
		collect->frame = 20;
		imgs++;
	}
	if (imgs == 0)
		collect->current_img = collect->imag_collect0;
	else if (imgs == 1)
		collect->current_img = collect->imag_1;
	else if (imgs == 2)
		collect->current_img = collect->imag_2;
	collect->frame--;
}

void	enemy_animation(t_game *enemy)
{
	static int	frame;
	static int	imgs;

	if (imgs == 3)
	{
		imgs = 0;
		frame = 0;
	}
	if (frame == 5)
	{
		frame = 0;
		imgs++;
	}
	if (imgs == 0)
		enemy->en_current_img = enemy->enemy_0;
	else if (imgs == 1)
		enemy->en_current_img = enemy->enemy_1;
	else if (imgs == 2)
		enemy->en_current_img = enemy->enemy_2;
	frame++;
}
