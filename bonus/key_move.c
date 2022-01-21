/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:43:11 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/19 14:56:46 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	right(t_game *game)
{
	game->player.ft_img_0 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_R_0.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_1 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_R_1.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_2 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_R_2.xpm", &game->img_size.x,
			&game->img_size.y);
}

void	left(t_game *game)
{
	game->player.ft_img_0 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_L_0.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_1 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_L_1.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_2 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_L_2.xpm", &game->img_size.x,
			&game->img_size.y);
}

void	up(t_game *game)
{
	game->player.ft_img_0 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_U_0.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_1 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_U_1.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_2 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_U_2.xpm", &game->img_size.x,
			&game->img_size.y);
}

void	down(t_game *game)
{
	game->player.ft_img_0 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_D_0.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_1 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_D_1.xpm", &game->img_size.x,
			&game->img_size.y);
	game->player.ft_img_2 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_sprint/naruto_sprint_D_2.xpm", &game->img_size.x,
			&game->img_size.y);
}

void	nature(t_game *game)
{
	game->player.ft_img_0 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_frame_0.xpm", &game->img_size.x, &game->img_size.y);
	game->player.ft_img_1 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_frame_1.xpm", &game->img_size.x, &game->img_size.y);
	game->player.ft_img_2 = mlx_xpm_file_to_image(game->mlx,
			"xpm/naruto_frame_2.xpm", &game->img_size.x, &game->img_size.y);
}
