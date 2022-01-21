/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:57:47 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/20 21:23:10 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

	i = 0;
	fd = open(file, O_RDONLY);
	count = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		count++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (count);
}
