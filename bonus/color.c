/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:09:08 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 01:35:11 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	color(t_game game)
{
	t_data	img;
	int		i;
	int		j;

	j = 0;
	img.imgs = mlx_new_image(game.mlx, game.win_size.x + IMAGE_SIZE / 2,
			game.win_size.y);
	img.addr = mlx_get_data_addr(img.imgs, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (j < game.win_size.y)
	{
		i = 0;
		while (i <= (game.win_size.x + IMAGE_SIZE / 2))
		{
			my_mlx_pixel_put(&img, i, j, 0x072227);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(game.mlx, game.win, img.imgs, 0, 0);
}
