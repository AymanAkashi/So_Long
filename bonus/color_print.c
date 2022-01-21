/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 01:35:17 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/21 01:36:35 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/so_long_bonus.h"

void	red(void)
{
	printf("\033[1;31m");
}

void	blue(void)
{
	printf("\033[0;34m");
}

void	yellow(void)
{
	printf("\033[0;33m");
}

void	purple(void)
{
	printf("\033[0;35m");
}

void	reset1(void)
{
	printf("\033[0m");
}
