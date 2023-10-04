// so_long.h

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_macos//mlx.h"
# include "../libft/libft.h"

//# include "custom_letters.h"
# include <fcntl.h> // Read
# include "string.h" // Strerror

/*
// GAME OBJECTS KEYS
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'
*/

// GAME KEYWORDS
# define ESC 65307
/*
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65363
# define D 100
# define RIGHT 65363
# define RESTART  114

# define MAX_FILES 1

# define TRUE 1
# define FALSE 0

# define CELL_SIZE 32

typedef struct s_game_objs
{
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*collectible;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	woid	*floor;
	int 	img_width;
	int 	img_height;
}	t_game_objs;

typedef struct s_game_positions
{
	int 	player_row;
	int		player_col;
	int 	exit_row;
	int 	exit_col;
}	t_game_positions;

// GAME DATA OF THE OBJECTS INSIDE THE MATRICE (INTERNAL)
typedef struct s_game_data
{
	int		count_player;
	int 	count_exit;
	int 	count_collectible;
	int 	count_wall;
	int 	count_empty;
	int 	count_movements;
	int 	endgame;
}	t_game_data;

// GAME RESOLUTIONS
typedef struct s_game_resolutions
{
	int 	settings_map_width;
	int 	setting_map_height;
	char 	*settings_name_window,
	char	*settings_name_maps;
}	t_game_resolutions;

// GAME DATA OF MATRICE EXTERN)
typedef struct s_map_data
{
	int 				first_read_matrice;
	int 				cols_matrice;
	int 				rows_matrice;
	int 				size_matrice;
	char				*matrice;
	t_game_resolutions resolutions;
	t_game_positions	positions;
}	t_map_data;

//MAIN GAME CONTROLLER
typedef struct s_game_instance
{
	void				*mlx;
	void				*win_ptr;
	int 				argc_tmp;
	char				**argv_tmp;
	t_map_data			map_init;
	t_game_positions 	positions_init;
	t_game_data 		game_data;
	t_game_resolutions 	resolutions_int;
	t_game_objs			game_objs;
}		t_game_instance;

//--------------------------STARTS HERE
// Function to start and initializes
int 	main(int argc, char **argv);
//--------------------------GAME INIT
// Function to initialize all structs
void		ft_struct_init(t_game_instance *game_init);
// Function to initializes and sets the properties
void		ft_initialize_game(t_game_instance *game_init);
// --------------------- GAME EVENTS
// Function to check an event handler for keyboard
int			ft_check_keyboard(int key, t_game_instance *game_init);
int			ft_non_special(int key, t_game_instance *game_init);
// Function to free() and quit the program
int			ft_exit_program(t_game_instance *game_init);
// Function to free() and reset the game
void		ft_reset_game(t_game_instance *game_init);
// --------------------- MAP VALIDATIONS AND MAP DATA
// Function to open and read the map file
int			ft_open_map(char *map, t_game_instance *game_init);
// Function to count the map content for ft_calloc (reserved space to read)
int			ft_read_count_map(char *map);
int			ft_count_lines(int fd);
// Function to calculate the map structure (rows, cols and matrice)
int			ft_map_dimensions(t_game_instance *game_init);
int			get_rows_count(t_game_instance *game_init);
int			get_cols_count(t_map_data *map_init);
// Function to reads a map from a file, validates it, and sets the instance
int			ft_read_map(int fd, t_game_instance *game_init);
int			ft_check_read(t_game_instance *game_init);
// Function to checks if the map has a valid .ber extension and path/
int			ft_map_extension(char *map);
// Function to checks if the map is valid
int			ft_is_valid_map(t_game_instance *game_init);
// Function to checks if the map is rectangular/square
int			ft_is_map_shape_valid(t_game_instance *game_init);
// Function to checks if the map is closed/surrounded by walls
int			ft_is_wall(t_game_instance *game_init);
// Function to counts the number of objects
int			ft_count_map_objects(t_game_instance *game_init);
// Function checks if the map has at 1 player, 1 exit >= collectible
int			ft_have_requires(t_game_instance *game_init);
// --------------------- GAME EVENTS/ACTIONS + GRAPHICS
// Function to call for events
void		ft_gameplay_start(t_game_instance *game_init);
// Function to takes a keyboard input and performs corresponding actions
int			ft_events_pressed(t_game_instance *game_init, int column, int row);
void		ft_win(t_game_instance *game_init);
// Function to prints the current number of movements on the terminal shell
int			ft_print_shell(t_game_instance *game_init);
// Function to frees all the memory allocated during the game and exit
int			ft_exit_program(t_game_instance *game_init);
// Function to frees all the memory allocated and reset game
void		ft_reset_game(t_game_instance *game_init);
// Function to finds the player position and performs actions
void		ft_locate_player(t_game_instance *game_init);
// --------------------- GRAPHICS + EVENTS
// Function to loads the different game images
void		ft_img_init(t_game_instance *game_init);
// Function to validate the files .xpm
void		ft_check_img(t_game_instance *game_init, void **image, char *path);
// Function to draws the game map on screen, placing each object
int			ft_map_draw(t_game_instance *game_init);
void		ft_map_continues(t_game_instance *game_init, int column, int row);
// Function to sets the image of an object in the corresponding cell on game
void		ft_set(t_game_instance *game_init, void *img, int wid, int hgt);
int			ft_map_extension(char *map);
// Function to checks if the map is valid
int			ft_is_valid_map(t_game_instance *game_init);
// Function to checks if the map is rectangular/square
int			ft_is_map_shape_valid(t_game_instance *game_init);
// Function to checks if the map is closed/surrounded by walls
int			ft_is_wall(t_game_instance *game_init);
// Function to counts the number of objects
int			ft_count_map_objects(t_game_instance *game_init);
// Function checks if the map has at 1 player, 1 exit >= collectible
int			ft_have_requires(t_game_instance *game_init);
// --------------------- GAME EVENTS/ACTIONS + GRAPHICS
// Function to call for events
void		ft_gameplay_start(t_game_instance *game_init);
// Function to takes a keyboard input and performs corresponding actions
int			ft_events_pressed(t_game_instance *game_init, int column, int row);
void		ft_win(t_game_instance *game_init);
// Function to prints the current number of movements on the terminal shell
int			ft_print_shell(t_game_instance *game_init);
// Function to frees all the memory allocated during the game and exit
int			ft_exit_program(t_game_instance *game_init);
// Function to frees all the memory allocated and reset game
void		ft_reset_game(t_game_instance *game_init);
// Function to finds the player position and performs actions
void		ft_locate_player(t_game_instance *game_init);
// --------------------- GRAPHICS + EVENTS
// Function to loads the different game images
void		ft_img_init(t_game_instance *game_init);
// Function to validate the files .xpm
void		ft_check_img(t_game_instance *game_init, void **image, char *path);
// Function to draws the game map on screen, placing each object
int			ft_map_draw(t_game_instance *game_init);
void		ft_map_continues(t_game_instance *game_init, int column, int row);
// Function to sets the image of an object in the corresponding cell on game
void		ft_set(t_game_instance *game_init, void *img, int wid, int hgt); */



#endif
