/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:22:38 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 01:31:21 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	remove_player(t_game *game)
{
	game->player.tile->type = Empty;
	game->player.tile = NULL;
}

int	start_game(int ac, char **av, t_game *game)
{
	if (ac != 2)
		return (0);
	check_name(av[1]);
	game->moves = 0;
	game->collect = 0;
	game->filemap = init_map(av, game);
	if (game->filemap == NULL)
		return (0);
	game->og_collect = game->collect;
	move_game(game);
	game_init(game);
	return (1);
}

void	print_move(int move)
{
	yellow();
	printf("Moves -> %d\n", move);
}

int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_game(game);
	if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	else if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up, (int)KEY_UP);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down, (int)KEY_DOWN);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left, (int)KEY_LEFT);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right, (int)KEY_RIGHT);
	else
		return (0);
	if (moved)
		print_move(++game->moves);
	game->count = 0;
	return (1);
}
