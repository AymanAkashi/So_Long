/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <aaggoujj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:27:42 by aaggoujj          #+#    #+#             */
/*   Updated: 2022/02/09 11:37:22 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMAGE_SIZE 50

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<mlx.h>
# include"../libft/libft.h"
# include"get_next_line_bonus.h"


typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}		t_bool;

typedef enum e_check
{
	Empty = '0',
	Wall = '1',
	Collect = 'C',
	Exit = 'E',
	Player = 'P',
	Enemy = 'X',
}		t_check;

typedef struct s_size
{
	int		x;
	int		y;
}	t_size;

typedef struct s_type
{
	t_check			type;
	t_check			or_type;
	t_size			verct;
	struct s_type	*up;
	struct s_type	*down;
	struct s_type	*left;
	struct s_type	*right;
}	t_type;

typedef enum s_enemy_type
{
	Herozentall = 'H',
	Verticall = 'V',
}		t_enemy_type;

typedef struct s_enemy
{
	int				dir;
	int				count;
	t_enemy_type	type;
	t_type			*og_tile;
	t_type			*tile;
	struct s_enemy	*next;
	int				frame;
}		t_enemy;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 119,
	ESC = 53
};

typedef struct s_collect
{
	int		frame;
	int		collect;
	void	*imag_collect0;
	void	*imag_1;
	void	*imag_2;
	void	*current_img;
}		t_collect;

typedef struct s_player
{
	t_type	*tile;
	void	*current_img;
	int		framecount;
	int		ft_frames;
	void	*ft_img_0;
	void	*ft_img_1;
	void	*ft_img_2;
	int		action_frames;
	void	*action_img;
	t_size	pos;
}			t_player;

typedef struct s_game
{
	t_type		**filemap;
	void		*mlx;
	void		*win;
	t_size		img_size;
	int			moves;
	int			collect;
	int			og_collect;
	t_collect	collect_img;
	t_size		win_size;
	void		*door_close;
	void		*door_open;
	void		*wall;
	t_player	player;
	int			count;
	void		*en_current_img;
}			t_game;

//put string and exit program
void	ft_exit_ps(char *arg, int err);
//reset of game take all origenal type and restort the orginall map
int		reset(t_game *game);

//generation map & define the character
t_type	**gen_map(char **map, t_game *game);

//draw img in the windows
void	render(t_game game);
//open image in void pointer
void	open_img(t_game *game);
void	color(t_game *game);

//counter of  line y of map
int		counter_fd(char *file);
int		counter_y(char **map);

//initalisation of map
t_type	**init_map(int fd, t_game *game, char **av);
//read map from file descriptor
char	**read_map(int fd, char **map, char *file);
char	*ft_strdup_n(const char *s1);

//move to next direction and swap the element if not empty
t_bool	move_to(t_game *game, t_type *tile);

//ending of game & remove player
void	remove_player(t_game *game);
int		end_game(t_game *game);
int		end_game_2(t_game *game);

//animation
void	collec_animation(t_collect *collect);
void	player_animation(t_player *player, t_game *game);
void	enemy_animation(t_game *enemy);
int		enemy_move(t_game *effect);
void	move_enemies(t_game *game);
void	move_game(t_game *game);

//free all alloceted heap memory
void	free_map(char **map);
void	free_filemap(t_game *game);

//check map if is valide or not
void	check_name(char *str);
void	check_one(char **str);
void	check_name(char *str);
int		check_char(char c);
void	check_all(char **str);
int		is_wall(char **str);
int		is_rect(char **str);
int		check_map(char **map);

//starting game
int		loop(t_game *game);
int		input(int key, t_game *game);
void	game_init(t_game *game);
int		start_game(int ac, char **av, t_game *game);

//color text
void	red(void);
void	blue(void);
void	yellow(void);
void	purple(void);
void	reset1(void);

#endif
