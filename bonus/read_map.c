/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:00:08 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 01:08:55 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	**read_map(char *file, char **map)
{
	int		fd;
	int		i;
	char	*str;
	int		len;

	fd = open(file, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	if (!str || str[i] == '\0')
		return (0);
	len = ft_strlen(str);
	map = malloc(sizeof(char *) * (counter_fd(file) + 1));
	while (str)
	{
		*(map + i) = ft_strdup(str);
		len = ft_strlen(str);
		free(str);
		i++;
		str = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}
