/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:47 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 00:59:46 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	counter_y(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	return (i);
}

char	*ft_strdup_n(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	counter_fd(char *file)
{
	int		fd;
	char	*str;
	int		count;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	count = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		count++;
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}
