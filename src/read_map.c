/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:00:08 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/20 23:09:53 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**read_map(int fd, char **map, char *file)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = get_next_line(fd);
	len = ft_strlen(str);
	map = malloc(sizeof(char *) * (counter_fd(file) + 1));
	while (str)
	{
		*(map + i) = ft_strdup(str);
		free(str);
		i++;
		str = get_next_line(fd);
	}
	free(str);
	map[i] = NULL;
	return (map);
}
