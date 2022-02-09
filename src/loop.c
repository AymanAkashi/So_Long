/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:24:26 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/02/09 13:57:52 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_game(t_game *game)
{
	game->player.action_frames = 10;
	game->player.ft_frames = 15;
	game->collect_img.frame = 20;
}

int	loop(t_game *game)
{
	render(*game);
	return (1);
}
