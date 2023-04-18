/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 03:12:29 by bsaeed            #+#    #+#             */
/*   Updated: 2023/04/13 09:17:33 by hakaddou         ###   ########.fr       */
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
void			free_rgbs(t_cub *cub);
int				check_rgbs(char **line);
void			convert_colors(t_cub *cub, char *rgb, int flag);
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
void			memset_map(t_cub *cub, char **tmp_map, char flag);
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
void			get_player_index(t_cub *cub, int *x, int *y);

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
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

/* bressenhams line drawing */

void			ft_swap(double *a, double *b);
void			ft_drawlinex(t_img *img, t_point start, t_point end, int color);
void			ft_drawliney(t_img *img, t_point start, t_point end, int color);
long			absolute(long num);
void			help_for_draw(t_img *img, t_point s, t_point e, int c);
void			draw_bressen_line(t_img *img, t_point s, t_point e, int c);

/* drawing_utls*/
void			draw_circle(t_img *img, t_circle circle, int color);
void			draw_bressen_line(t_img *img, t_point s, t_point e, int c);
void			init_point(t_point *point, int x, int y);
void			init_circle(t_circle *circle, int x, int y, int radius);
void			draw_rectangle(t_img *img, t_rect rect, int color);
t_rect			init_rect(int x, int y, int width, int height);
long			absolute(long num);

/* mlx utils*/
void			*free_img(void *img_ptr, void *mlx);
void			*free_window(void *mlx, void *win);
void			*cub_new_img(t_img *img, void *mlx, int width, int height);
void			init_mlx_utils(t_cub *cub);

/* raycasting*/
int				return_tex_val(t_cub *c, int x, t_wall_cords cords, t_ray *r);
void			draw_3d_ceiling(t_cub *cub, int wall_top_pixel, int x);
void			draw_3d_floor(t_cub *cub, int wall_bottom_pixel, int x);
void			draw_3d_wall(t_cub *cub, int x, t_ray *rays);
void			generate_3d_wprojection(t_player *p, t_ray *r, t_cub *c);
void			render_color_buffer(t_cub *cub);
void			init_player_pos(t_player *player);
void			init_player(t_player *player, t_cub *cub);
void			init_map(t_cub *cub);
void			set_minimap_scalefactor(t_cub *cub);
void			setup(t_cub *cub);
void			render_player(t_player *player, t_cub *cub);
void			draw_cross(t_point cross, int size, int color, t_cub *cub);
double			return_smallest(double a, double b);
void			draw_middle_circle(t_cub *cub, t_ray *rays);
void			render_rays(t_cub *cub, t_ray *rays);
void			move_player(t_player *player, int flag);
void			normalize_angle(double *angle);
void			set_h_ray_point(double ray_angle, t_ray *ray, t_player *player);
void			cast_horz_ray(double ray_angle, t_ray *ray, t_player *player);
void			set_v_ray_point(double ray_angle, t_ray *ray, t_player *player);
void			cast_vert_ray(double ray_angle, t_ray *ray, t_player *player);
void			cast_ray(double ray_angle, t_ray *ray, int sid, t_player *p);
void			cast_all_rays(t_ray *rays, t_player *player);
void			update(t_cub *cub);
void			render(t_cub *cub);
void			raycasting(t_cub *cub);
void			init_ray(double ray_angle, t_ray *ray, int stripid);
double			delta_points(double x1, double y1, double x2, double y2);
void			set_horz_data(t_ray *ray);
void			set_vert_data(t_ray *ray);
void			calculate_smallest_distance(t_ray *ray, t_player *player);

/*	key handles	*/
void			rerender(t_cub *cub);
void			mouse_funcs(t_cub *cub, int flag);
int				mouse_events(int x, int y, t_cub *cub);
void			animate_aim(t_cub *cub);
void			check_for_exit(int key, t_cub *cub);
void			check_left_right_move(int key, t_cub *cub);
void			check_player_movement(int key, t_cub *cub);
void			check_direction(int key, t_cub *cub);
void			check_full_screen(int key, t_cub *cub);
void			check_quitting_mini_map(int key, t_cub *cub);
void			check_map_scaling(int key, t_cub *cub);
void			check_aiming(int key, t_cub *cub);
int				keys_handler(int key, t_cub *cub);
void			check_tracking(int key, t_cub *cub);
int				keys_released(int key, t_cub *cub);
int				exit_app(t_cub *cub);
void			check_anim_aim(t_cub *cub);
void			start_mouse(t_cub *cub);
int				render_loop(t_cub *cub);
void			hook_keys(t_cub *cub);

/*	parsing utils	*/
char			*ft_tex_dup(const char *s1);
size_t			ft_tex_len(const char *s);
int				return_split_len(char **split);
void			trim_map_spaces(char *str);
void			free_texes(t_cub *cub);
void			exit_cub(t_cub *cub, int code, char *msg);
void			set_player_direction(t_cub *cub);
void			parse_info(t_cub *cub);
void			parse_map(t_cub *cub);
void			check_player_walls(t_cub *cub);
void			check_for_walls(t_cub *cub);
void			get_player_index(t_cub *cub, int *x, int *y);
void			check_map_lines(t_cub *cub);
void			validations(t_cub *cub);
void			free_rgbs(t_cub *cub);
int				check_rgbs(char **line);
void			convert_colors(t_cub *cub, char *rgb, int flag);
int				parse(int ac, t_cub *cub, char *map_file);
char			*take_map_input(int fd, t_cub *cub);
void			realloc_map(t_cub *cub);
void			check_map_pos(t_cub *cub, char **half_map);
void			check_pos_helper(t_cub *cub);
void			check_pos_helper2(t_cub *cub);
void			check_positions(t_cub *cub);
void			check_other_format_1d(t_cub *cub);
int				check_up(t_cub *cub, int i, int j);
int				check_down(t_cub *cub, int i, int j);
int				check_left(t_cub *cub, int i, int j);
int				check_right(t_cub *cub, int i, int j);
void			all_wall_checks(t_cub *cub, int i, int j);
void			check_borders(t_cub *cub);

/*	free utils	*/
void			exit_cub(t_cub *cub, int code, char *msg);

/*	map	*/
void			render_map(t_cub *cub);
bool			maphaswallat(double x, double y, t_player *player);
int				get_map_at(int i, int j, t_player *player);
bool			is_inside_map(double x, double y, t_player *player);
double			return_smallest(double a, double b);

#endif
