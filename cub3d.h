/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:12:29 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 04:07:19 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <stdbool.h>
# include "./mlx/mlx.h"
# include "./includes/constants.h"
# include "./includes/keys.h"
# include "./includes/shapes.h"
# include "./includes/colors.h"
# include "./includes/raycasting.h"
# include <strings.h>

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
	t_keys			keys;
	int				*color_buffer;
	int				*tex;
	int				i;
	double			proj_wall_h;
	int				t_size;
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
	void			*sniper;
	int				ceiling_pos;
	int				map_pos;
	int				max;
	char			*trimmed;
	t_dir			dir;
	int				p_flag;
	int				m_flag;
	double			scale_factor;
	int				fps;
	double			aim_factor;
}				t_cub;

/* parsing utils */
int				ft_array_length(char **array);

//------------cub_utils_folder------------//

unsigned long	rgb_to_hex(int red, int green, int blue, t_cub *cub);
int				ft_array_length(char **arr);
void			ft_free(char ***arr);
/*parsing*/

int				ft_file_ext(t_cub *cub, char *map_file);
void			parse_info(t_cub *cub);
void			parse_map(t_cub *cub);
int				parse(int ac, t_cub *cub, char *map_file);
void			check_floor_ceiling(t_cub *cub);
void			check_north_south(t_cub *cub);
void			east_west(t_cub *cub);
char			*ft_tex_dup(const char *s1);
size_t			ft_tex_len(const char *s);
int				rgb(t_cub *cub, char *line, char flag);
void			trim_comma(char *str);
void			parse_rgb(t_cub *cub);
void			*allocate_new_map(t_cub *cub);
void			memset_map(t_cub *cub, char **tmp_map);
void			hadis_rectangle_map(t_cub *cub, char **tmp_map);
int				return_split_len(char **split);
int				get_longest_line(char **split);
int				init_textures(t_cub *cub);
void			init(t_cub *cub);
void			check_borders(t_cub *cub);
void			*callocer(int size, int block, t_cub *cub);
void			free_split(char ***split);
void			*free_null(void *ptr);
void			check_for_textures(t_cub *cub);
void			set_player_direction(t_cub *cub);

//parse_utils2
int				ft_close(int fd);
void			null_params(char **tmp, char **total, char **line);
void			free_params(char **line, char **tmp, char **input);
int				return_len(char **split);
void			arg_count(int ac);

//parse_utils3
int				get_longest_line(char **split);
void			convert_space_to_wall(t_cub *cub);
void			convert_spaces(t_cub *cub);
int				is_valid_char(char c);
void			trim_spaces(char *str);

//parse_utils5
int				return_double_len(char **split);
char			*ft_maptrim(char const *s1, char const *set);
void			trim_comma(char *str);
int				check_next_line(t_cub *cub, char *str, int len);
void			check_for_lines(t_cub *cub);

//parse_utils6
int				check_spaces(char *str);
void			check_other_format(t_cub *cub);
void			check_player_format_two(t_cub *cub);
void			check_player_format(t_cub *cub);
void			check_lines(char *str, t_cub *cub);
//parsemap1
char			*take_map_input(int fd, t_cub *cub);
void			realloc_map(t_cub *cub);
void			check_map_pos(t_cub *cub, char **half_map);
void			check_positions(t_cub *cub);
void			check_other_format_1d(t_cub *cub);
/*print functions to delete later*/
void			print_map_two(char **split);
void			print_cub(t_cub *cub);

/* mlx utils */
void			*free_img(void *img_ptr, void *mlx);
void			*free_window(void *mlx, void *win);
void			*cub_new_img(t_img *img, void *mlx, int width, int height);
int				keys_handler(int key, t_cub *cub);
int				exit_app(t_cub *cub);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			hook_keys(t_cub *cub);

/* bressenhams line drawing */

void			ft_swap(double *a, double *b);
void			ft_drawlinex(t_img *img, t_point start, t_point end, int color);
void			ft_drawliney(t_img *img, t_point start, t_point end, int color);
long			absolute(long num);
void			help_for_draw(t_img *img, t_point s, t_point e, int c);
void			draw_bressen_line(t_img *img, t_point s, t_point e, int c);
void			draw_dda_line(t_img *img, t_point s, t_point e, int c);

/* drawing_utls*/
void			draw_circle(t_img *img, t_circle circle, int color);
void			draw_bressen_line(t_img *img, t_point s, t_point e, int c);
void			init_point(t_point *point, int x, int y);
void			init_circle(t_circle *circle, int x, int y, int radius);
void			draw_rectangle(t_img *img, t_rect rect, int color);
t_rect			init_rect(int x, int y, int width, int height);
void			rasterize_circle(t_img *img, t_circle circle, int color);
long			absolute(long num);

/* mlx utils*/
void			*free_img(void *img_ptr, void *mlx);
void			*free_window(void *mlx, void *win);
void			*cub_new_img(t_img *img, void *mlx, int width, int height);
void			init_mlx_utils(t_cub *cub);

/* raycasting*/
void			raycasting(t_cub *cub);
void			draw_background(t_img *img, t_cub *cub);
void			render(t_cub *cub);
void			update(t_cub *cub);

/*	free utils	*/
void			exit_cub(t_cub *cub, int code, char *msg);

/*	map	*/
void			render_map(t_cub *cub);
bool			maphaswallat(double x, double y, t_player *player);
int				get_map_at(int i, int j, t_player *player);
bool			is_inside_map(double x, double y, t_player *player);
double			return_smallest(double a, double b);

/*	bonus	*/
void			render_gun(t_cub *cub);
#endif
