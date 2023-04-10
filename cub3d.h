
#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/errno.h>
# include <string.h>
# include <stdarg.h>
# include <math.h>
#include <stdbool.h>
#include "./mlx/mlx.h"
#include "./includes/constants.h"
#include "./includes/keys.h"
#include "./includes/shapes.h"
#include "./includes/colors.h"
#include "./includes/raycasting.h"
#include <strings.h>


// texture

# define TEXTURE_HEIGHT 			64
# define TEXTURE_WIDTH 				64

typedef struct s_state
{
	t_point			position;
	t_point			direction;
	t_point			plane;
}			t_state;

// screen struct
typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;


// textures struct
typedef struct s_img2
{
	void	*img_ptr;
	int		*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img2;


// player struct
typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
	int	p;
	int	scale_flag;
}				t_key;

typedef struct s_buff
{
	char	*i;
	char	*total;
	char	*tmp;
	char	*line;
}	t_buff;

typedef struct s_dir
{
	int		south;
	int		north;
	int		west;
	int		east;
	double	actual_dir;
}				t_dir;


// map struct
typedef struct s_cub
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img2			img2[4];
	char			**rgb;
	char			**xpm;
	char			**map;
	int				n_rows;
	int				n_columns;
	unsigned long	floor;
	unsigned long	ceiling;
	uint32_t		texture[4][TEXTURE_HEIGHT * TEXTURE_WIDTH];
	t_key			key;
	t_point			start_line_pos;
	t_point			end_line_pos;
	t_player		player;
	float			fps;
	t_keys			keys;
	int				*color_buffer;
	int				*tex;
	int				i;
	double			proj_wall_h;
	int				t_size;
	double			dist_proj_plane;
	int				wall_strip_height;
	int				wall_top_pixel;
	int				wall_bottom_pixel;
	char			*map_1d;
	int				map_1d_len;
	char			*c_rgb;
	char			*f_rgb;
	bool			color_flag;
	int				fd;
	int				no_pos;
	int				so_pos;
	int				we_pos;
	int				ea_pos;
	int				floor_pos;
	int				ceiling_pos;
	int				map_pos;
	int				max;
	char			*trimmed;
	t_dir			dir;
	int				p_flag;
	double			scale_factor;
}				t_cub;

// raycasting struct

// typedef struct s_ray
// {
// 	t_point	ray_dir;
// 	t_point	side_dist;
// 	t_point	delta_dist;
// 	int		map_x;
// 	int		map_y;
// 	double	perspective_wall_distance;
// 	int		step_x;
// 	int		step_y;
// 	int		side;
// }			t_ray;


/* parsing utils */
void	ft_free(char ***array);
int		ft_array_length(char **array);
char	**ft_reallocation(char **pointer, int size);
void	print_map(char **map);


//------------cub_utils_folder------------//

//const char		*get_exit(const char *file);
unsigned long	rgb_to_hex(int red, int green, int blue, t_cub *cub);

// int				get_next_line(int fd, char **line);
// int				ft_new_line(char *buf);
int				ft_array_length(char **arr);
// int				ft_strncmp(const char *s1, char *s2, size_t n);
// int				ft_atoi(const char *str);

void			ft_free(char ***arr);


/*parsing*/

int		ft_file_ext(t_cub *cub, char *map_file);
void	parse_info(t_cub *cub);
void		parse_map(t_cub *cub);
int		parse(int ac, t_cub *cub, char *map_file);
void	print_cub(t_cub *cub);


int		check_characters(t_cub *cub);
int		init_textures(t_cub *cub);
int		init_colors(t_cub *cub);
void	init(t_cub *cub);


/* mlx utils */
void	*free_img(void *img_ptr, void *mlx);
void	*free_window(void *mlx, void *win);
void	*cub_new_img(t_img *img, void *mlx, int width, int height);
int		keys_handler(int key, t_cub *cub);
int		exit_app(t_cub *cub);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	hook_keys(t_cub *cub);

/* bressenhams line drawing */

void	ft_swap(double *a, double *b);
void	ft_drawlinex(t_img *img, t_point start, t_point end, int color);
void	ft_drawliney(t_img *img, t_point start, t_point end, int color);
long	absolute(long num);
void	help_for_draw(t_img *img, t_point start, t_point end, int color);
void	draw_line(t_img *img, t_point start, t_point end, int color);

/* drawing_utls*/
void	draw_circle(t_img *img, t_circle circle, int color);
void	draw_line(t_img *img, t_point start, t_point end, int color);
void	init_point(t_point *point, int x, int y);
void	init_circle(t_circle *circle, int x, int y, int radius);
void	draw_rectangle(t_img *img, t_rect rect, int color);
t_rect	init_rect(int x, int y, int width, int height);

/* mlx utils*/
void	*free_img(void *img_ptr, void *mlx);
void	*free_window(void *mlx, void *win);
void	*cub_new_img(t_img *img, void *mlx, int width, int height);
void	init_mlx_utils(t_cub *cub);

/* raycasting*/
void	raycasting(t_cub *cub);
void	draw_background(t_img *img, t_cub *cub);
void	render(t_cub *cub);
void	update(t_cub *cub);

/*	free utils	*/
void	exit_cub(t_cub *cub, int code, char *msg);

/*	map	*/
void	render_map_two(t_cub *cub);
void	render_map(t_cub *cub);
bool	maphaswallat(double x, double y);
int		get_map_at(int i, int j);
bool	is_inside_map(double x, double y);
#endif

