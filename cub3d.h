/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:33:00 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/18 00:45:03 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "libft/get_next_line/get_next_line_bonus.h"
# include "libft/libft.h"
# include <math.h>

typedef struct s_texture
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int				floor;
	int				ceileng;
}				t_texture;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_cord
{
	int	x;
	int	y;
}				t_cord;

typedef struct s_contact
{
	t_point	r;
	double	distance;
}				t_contact;

typedef struct s_segm
{
	t_point	start;
	t_point	end;
}				t_segm;

typedef struct s_player
{
	t_point		p;
	t_vector	v;
	double		angle;
	double		speed;
}				t_player;

typedef struct s_ray
{
	t_point	p;
	double	dist;
	char	side;
}				t_ray;

typedef struct s_parse
{
	char		*split_line;
	char		*map_line;
	char		**full_file;
	t_player	*player;
	char		**mapo;
	char		*so;
	char		*we;
	char		*ea;
	char		*no;
	char		*c;
	char		*f;
	int			error_find;
	int			map_start;
}				t_parse;

typedef struct s_map
{
	char		*split_line;
	char		*map_line;
	char		**full_file;
	t_player	*player;
	char		**mapo;
	char		*so;
	char		*we;
	char		*ea;
	char		*no;
	char		*c;
	char		*f;
	int			wide;
	int			len;
	int			error_find;
	int			map_start;
}				t_map;

typedef struct s_window
{
	t_player	*player;
	mlx_image_t	*img;
	mlx_t		*mlx_ptr;
	t_map		*map;
	t_texture	t;
	t_cord		*screen;
}				t_window;

void		draw_line(t_window *win, t_point start, t_point end);
void		player_drawer(t_window *win, t_point pos, int color);
t_vector	ft_draw_map(t_window *win, char **matrix, t_point next_pos,
				t_vector v);
t_point		assign_point(double x, double y);
t_point		assign_int_point(int x, int y);
double		angle_adjast(double angle, char sign);
void		init_val(t_window *win);
t_vector	assign_vect(double vx, double vy, double angle);
t_point		pos_adjast(t_window *win, t_point pos);
int			check_inside(t_window *win, t_point player);
t_segm		wall(t_cord cord, t_window *win, t_vector v, int is_it_x);
t_ray		draw_scene(t_window *win, t_point next_pos, t_ray r);
t_vector	rotation_vect(t_vector vect, double deg);
void		draw_background(t_window *win, int floor, int ceiling);
void		draw_line(t_window *win, t_point start, t_point end);
void		cub_drawer(t_window *win, t_point start, t_point end, int color);
void		texturess(t_window *win, t_ray r, t_cord cord);
t_ray		raycast(t_window *win, int side, t_point pos, t_vector v);
double		norme_vect(t_vector vect);
double		dot_vect(t_vector vect, t_vector vect2);
t_cord		assign_cord(int x, int y);
t_point		in_cube_pos(t_window *win, t_cord cord, t_vector v);
void		error(void);
void		free_all(t_window *win);

//parse
void		ft_exit(char *message);
void		check_lines(char *file);
t_player	*get_player_location(t_player *player, t_map *g, int *a);
void		check_borders_col(t_map *g);
void		check_borders_line(t_map *g);
int			get_text(t_map *g);
int			play_char(char c, int *a);
int			check_map_line(char **str);
void		ft_start(t_map *g);
char		**convert_map(char *line);
int			get_map(int fd, t_map *g);
int			get_data(int fd, t_map *g);
void		get_len_wide(t_map *g);
void		exit_all(t_map *g, char *str);
void		free_txt(t_map *g, char *str);
void		exit_map_error(t_map *g, char *str);
void		exit_from_start(t_window *win);
void		parser(t_map *g, int fd);
void		get_last_n_line(char *line, char **kep);
int			get_color(char *color, int r, int g, int b);
int			play_char(char c, int *a);

#endif