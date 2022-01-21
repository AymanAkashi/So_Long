/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:47:05 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 02:48:49 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

int	is_rect(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (str[i][len] != '\n' && str[i][len] != '\0')
		len++;
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

// int check_null(char **str)
// {
// 	int i;
// 	int j;
// 	int len;
// 	len = counter_y(str);
// 	i = 0;
// 	while(i < len)
// 	{
// 		j = 0;
// 		while(str[i][j])
// 			{
// 				if(str[i][j] == '\n' && str[i][j + 1] == '\0' &&
// 					str[i][j + 2] == '\0')
// 					return (0);
// 				j++;
// 			}
// 			i++;
// 	}
// 	return (0);
// }

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
