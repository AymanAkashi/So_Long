# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 17:11:38 by aaggoujj          #+#    #+#              #
#    Updated: 2022/01/18 05:44:46 by aaggoujj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_strchr.c ft_strlcat.c ft_strlen.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_strnstr.c \
			ft_strncmp.c ft_strlcpy.c ft_strdup.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c
OBJS :=$(SRCS:.c=.o)

BONUS	=    ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			 ft_lstclear.c ft_lstiter.c ft_lstmap.c


NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BLUE = '\033[0;34m'

BONUS_OBJS :=$(BONUS:.c=.o)
INCLUDES = libft.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJS)
		@echo $(CURSIVE)$(BLUE) " 						- Compiling $(NAME)..." $(NONE)
		@ar -rcs $(NAME) $(OBJS)
%.o: %.c
		@gcc $(CFLAGS) -c $< -I$(INCLUDES) -o $@
clean:
		@rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
		@echo $(CURSIVE)$(YELLOW) " 						- Removing $(NAME)..." $(NONE)
		@rm -f $(NAME)
re: fclean all

bonus:		$(OBJS) $(BONUS_OBJS)
			ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
.PHONY: all clean fclean re
