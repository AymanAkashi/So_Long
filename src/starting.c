/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 04:22:38 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 09:33:07 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	remove_player(t_game *game)
{
	game->player.tile->type = Empty;
	game->player.tile = NULL;
}

int	start_game(int ac, char **av, t_game *game)
{
	int	fd;

	if (ac != 2)
		return (0);
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	game->moves = 0;
	game->collect = 0;
	game->filemap = init_map(fd, game, av);
	if (game->filemap == NULL)
		return (0);
	game->og_collect = game->collect;
	move_game(game);
	game_init(game);
	close(fd);
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
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		print_move(++game->moves);
	game->count = 0;
	return (1);
}
