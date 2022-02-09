/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:47:05 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/02/09 11:43:07 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
//checker of charachters
void	check_all(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!check_char(str[i][j]))
				ft_exit_ps("Map has undifined charchaer try another one", 1);
			j++;
		}
		i++;
	}
	check_one(str);
}
//verifie map is rectangle
int	is_rect(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i][j] != '\n' && str[i][j] != '\0')
		j++;
	len = j;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j])
			j++;
		if (j == len)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_one(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
	{
		if (str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

//verifie map is surround with wall
int	is_wall(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (str[i][j] != '\n' && str[i][j] != '\0')
		j++;
	len = j;
	while (str[i] != NULL)
		i++;
	if (!is_one(str[0]) || !is_one(str[i - 1]))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][len - 1] != '1')
			return (0);
		i++;
	}
	i--;
	if (str[i][len] == '\n' && str[i][len + 1] == '\0')
		ft_exit_ps("Wrong Map !\n", 1);
	return (1);
}
//verifie name of path
void	check_name(char *str)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * 5);
	if (!dest)
		exit(1);
	j = 0;
	i = ft_strlen(str);
	i--;
	while (i > (int)ft_strlen(str) - 5)
	{
		dest[j] = str[i];
		i--;
		j++;
	}
	dest[j] = '\0';
	if (ft_strncmp(dest, "reb.", 4))
	{
		free(dest);
		ft_exit_ps("The Path is invalide try file ends with '.ber'!\n", 1);
	}
	free(dest);
}
