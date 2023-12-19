/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:03:30 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/18 01:37:25 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vector	rotation_vect(t_vector vect, double deg)
{
	t_vector	new_vect;

	new_vect.x = vect.y * sin(deg) + vect.x * cos(deg);
	new_vect.y = vect.y * cos(deg) - vect.x * sin(deg);
	if (new_vect.y < 0.00000000000001
		&& new_vect.y > -0.0000000000001)
		new_vect.y = 0;
	if (new_vect.x < 0.00000000000001
		&& new_vect.x > -0.0000000000001)
		new_vect.x = 0;
	return (new_vect);
}

int	check_inside(t_window *win, t_point player)
{
	int	i;
	int	j;

	i = (player.y - 2) / 10;
	j = (player.x - 2) / 10;
	if (win->map->mapo[i][j] == '0' || win->map->mapo[i][j] == 'W'
			|| win->map->mapo[i][j] == 'E' || win->map->mapo[i][j] == 'N'
			|| win->map->mapo[i][j] == 'S')
		return (1);
	return (0);
}

t_point	mov_player(t_point player, t_vector v, mlx_t *mlxp)
{
	t_point	next_pos;

	next_pos = player;
	if (mlx_is_key_down(mlxp, MLX_KEY_W))
		next_pos = assign_point(next_pos.x + v.x,
				next_pos.y + v.y);
	if (mlx_is_key_down(mlxp, MLX_KEY_S))
		next_pos = assign_point(next_pos.x - v.x,
				next_pos.y - v.y);
	if (mlx_is_key_down(mlxp, MLX_KEY_D))
		next_pos = assign_point(next_pos.x + v.y,
				next_pos.y - v.x);
	if (mlx_is_key_down(mlxp, MLX_KEY_A))
		next_pos = assign_point(next_pos.x - v.y,
				next_pos.y + v.x);
	return (next_pos);
}

void	keyhook(void *param)
{
	t_window	*win;
	t_point		next_pos;
	t_ray		r;

	win = (t_window *)param;
	mlx_delete_image(win->mlx_ptr, win->img);
	win->img = mlx_new_image(win->mlx_ptr,
			win->screen->x, win->screen->y);
	if (mlx_is_key_down(win->mlx_ptr, MLX_KEY_RIGHT))
		win->player->angle = angle_adjast(win->player->angle, '+');
	if (mlx_is_key_down(win->mlx_ptr, MLX_KEY_LEFT))
		win->player->angle = angle_adjast(win->player->angle, '-');
	if (mlx_is_key_down(win->mlx_ptr, MLX_KEY_ESCAPE))
	{
		free_all(win);
		exit(0);
	}
	r.p = win->player->p;
	win->player->v = assign_vect(win->player->speed, 0, win->player->angle);
	next_pos = pos_adjast(win, mov_player(win->player->p,
				win->player->v, win->mlx_ptr));
	draw_background(win, win->t.floor, win->t.ceileng);
	r = draw_scene(win, next_pos, r);
	mlx_image_to_window(win->mlx_ptr, win->img, 0, 0);
}

void	init_val(t_window *win)
{
	win->player->speed = 0.6;
	win->player->v = assign_vect(win->player->speed, 0, win->player->angle);
	win->mlx_ptr = mlx_init(win->screen->x, win->screen->y,
			"Super Duper Cool 3D Game!!!", false);
	if (!win->mlx_ptr)
	{
		free_all(win);
		error();
	}
	win->img = mlx_new_image(win->mlx_ptr,
			win->screen->x, win->screen->y);
	if (!win->img)
	{
		free_all(win);
		error();
	}
	mlx_loop_hook(win->mlx_ptr, &keyhook, win);
	mlx_image_to_window(win->mlx_ptr, win->img, 0, 0);
	mlx_loop(win->mlx_ptr);
}
