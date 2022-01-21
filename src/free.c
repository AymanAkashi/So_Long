/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:56:50 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/18 10:04:05 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
