/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:48:36 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/19 13:44:07 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_door(t_game *game)
{
	game->door_close = mlx_xpm_file_to_image(game->mlx, "xpm/Door.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_open = mlx_xpm_file_to_image(game->mlx,
			"xpm/door_open.xpm", &game->img_size.x, &game->img_size.y);
}

void	open_player(t_game *game)
{
	game->player.current_img = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_frame_0.xpm", &game->img_size.x, &game->img_size.y);
}

void	open_collect(t_game *game)
{
	game->collect_img.current_img = mlx_xpm_file_to_image(game->mlx,
			"xpm/ramen.xpm", &game->img_size.x, &game->img_size.y);
}

void	open_img(t_game *game)
{
	open_collect(game);
	open_player(game);
	open_door(game);
	game->wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall_tree_1.xpm",
			&game->img_size.x, &game->img_size.y);
}
