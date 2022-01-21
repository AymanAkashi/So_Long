/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:50 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 01:07:44 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_filemap(t_game *game)
{
	t_type	**filemap;

	filemap = game->filemap;
	while (*game->filemap != NULL)
	{
		free(*game->filemap);
		game->filemap++;
	}
	free (filemap);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	free_enemies(t_game *game)
{
	t_enemy	*next;

	if (game->enemy == NULL)
		return ;
	while (TRUE)
	{
		next = game->enemy->next;
		free (game->enemy);
		if (next == NULL)
			break ;
		game->enemy = next;
	}
}
