/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:37:25 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/01/20 22:38:38 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdlib.h>
# include<unistd.h>

# define BUFFER_SIZE 1

char	*ft_strchr_g(char *s, int c);

size_t	ft_strlen_g(char *str);

char	*get_all_line(int fd, char *str);

char	*get_line(char *str);

char	*get_next_line(int fd);

char	*ft_strjoin_g(char *str, char *buff);

char	*get_rest(char *str);

#endif
