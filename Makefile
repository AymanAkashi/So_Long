NAME = so_long
INCLUDE = include
HEADER = $(INCLUDE)/so_long.h
HEADER_BONUS = $(INCLUDE)/so_long_bonus.h

BONUS_DIR = bonus/
SRCS_DIR = src/


LIBF_DIR = libft/
LIBFT_A = libft.a


OBJS_DIR = obj/
OBJS_BONUS_DIR = obj_bonus/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))
SRCS_BONUS = main.c check_map.c get_next_line_bonus.c get_next_line_utils_bonus.c free.c render.c enemy.c counter.c read_map.c define_map.c color.c map_init.c \
				open_img.c move.c key_move.c game_init.c animation.c check_char.c enemy_move.c loop.c reset.c starting.c color_print.c

SRCS = main.c check_map.c get_next_line_bonus.c get_next_line_utils_bonus.c free.c render.c counter.c read_map.c define_map.c color.c map_init.c \
		open_img.c move.c game_init.c check_char.c loop.c reset.c starting.c color_print.c

OBJS :=$(SRCS:.c=.o)
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRY='\033[2;37m'
CURSIVE='\033[3m'
RED ='\033[0;31m'
BLUE = '\033[0;34m'
			

all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS)) $(HEADER)
		
		@echo $(CURSIVE)$(BLUE) " 						- Making ft_libft..." $(NONE)		
		@make -C libft 
		@make -C $(LIBF_DIR) clean 
		@make GRAPHIC 
		@gcc $(CFLAGS) $(addprefix $(OBJS_DIR), $(OBJS)) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o ${NAME}
		@echo $(CURSIVE)$(BLUE) " 						- Compiling $(NAME) Mandatory... " $(NONE)
		@echo $(GREEN)"	                 - ------------------------------🅓 🅞 🅝 🅔----------------------------- -"$(NONE)

$(OBJS_DIR)%.o:	${SRCS_DIR}/%.c $(HEADER)
					@mkdir -p obj
					@gcc $(CFLAGS) -c -I $(INCLUDE) $< -o $@






bonus :	$(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS)) $(HEADER_BONUS)
		@echo $(CURSIVE)$(BLUE) " 						- Making libft..." $(NONE)		
		@make -C libft
		@make -C $(LIBF_DIR) clean
		@make GRAPHIC 
		@echo $(CURSIVE)$(BLUE) " 						- Compiling $(NAME) Bonus... " $(NONE)
		@gcc $(CFLAGS) $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS)) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o ${NAME}
		@echo $(GREEN)"	                 - ------------------------------🅓 🅞 🅝 🅔----------------------------- -"$(NONE)
		

GRAPHIC: 
			@echo $(CURSIVE)$(RED)"				░██████╗░█████╗░      ██╗░░░░░░█████╗░███╗░░██╗░██████╗░"$(NONE)
			@echo $(CURSIVE)$(RED)"				██╔════╝██╔══██╗      ██║░░░░░██╔══██╗████╗░██║██╔════╝░"$(NONE)
			@echo $(CURSIVE)$(RED)"				╚█████╗░██║░░██║      ██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"$(NONE)
			@echo $(CURSIVE)$(RED)"				░╚═══██╗██║░░██║      ██║░░░░░██║░░██║██║╚████║██║░░╚██╗"$(NONE)
			@echo $(CURSIVE)$(RED)"				██████╔╝╚█████╔╝      ███████╗╚█████╔╝██║░╚███║╚██████╔╝"$(NONE)
			@echo $(CURSIVE)$(RED)"				╚═════╝░░╚════╝░------╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"$(NONE)
			@echo $(CURSIVE)$(GREEN)"			         ───────────────────────────────────────────────────────"$(NONE)
			@echo $(CURSIVE)$(BLUE) " 						- Making object files..." $(NONE)
			

$(OBJS_BONUS_DIR)%.o: ${BONUS_DIR}/%.c ${HEADER_BONUS}
						@mkdir -p obj_bonus
						@gcc $(CFLAGS) -I $(INCLUDE) -c $< -o $@




						
clean:
		@echo $(CURSIVE)$(YELLOW) " 						- Removing object files..." $(NONE)
		@rm -rf $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS))

fclean: clean
		@echo $(CURSIVE)$(YELLOW) " 						- Removing $(NAME)..." $(NONE)
		@rm -rf $(NAME) $(NAME_BONUS)
		@echo $(CURSIVE)$(YELLOW) " 						- Removing object libft..." $(NONE)
		@make -C $(LIBF_DIR) fclean 
		@echo $(NONE) ""
norm: 
		@echo $(CURSIVE)$(YELLOW) "			check_normenette...."
		@norminette $(SRCS_DIR)*.c $(INCLUDE) $(BONUS_DIR)*.c

re: fclean all

.PHONY: all clean fclean re		@echo $(CURSIVE)$(BLUE) " 						- Making ft_libft..." $(NONE)		
		@make -C libft 
		@make -C $(LIBF_DIR) clean 
