/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:36:54 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/20 22:48:05 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/get_next_line_bonus.h"

char	*get_all_line(int fd, char *str)
{
	int		byte;
	char	*buff;

	byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		str = ft_strjoin_g(str, buff);
		if (ft_strchr_g(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*str[12288];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = get_all_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	dest = get_line(str[fd]);
	str[fd] = get_rest(str[fd]);
	return (dest);
}
