/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:05:16 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/18 09:52:39 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		ptr[i] = c;
		i++;
		n--;
	}
	return (ptr);
}
