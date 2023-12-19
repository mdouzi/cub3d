/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 04:28:17 by ohachami          #+#    #+#             */
/*   Updated: 2023/09/28 04:28:20 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	dot_vect(t_vector vect, t_vector vect2)
{
	double	dot;

	dot = vect.y * vect2.y + vect.x * vect2.x;
	return (dot);
}

double	norme_vect(t_vector vect)
{
	double	norme;

	norme = sqrt(pow(vect.x, 2) + pow(vect.y, 2));
	return (norme);
}

t_point	in_cube_pos(t_window *win, t_cord cord, t_vector v)
{
	t_point	cubepos;

	if (v.x > 0)
		cubepos.x = (cord.x * 10 + 12 - win->player->p.x) / 10;
	else
		cubepos.x = (win->player->p.x - cord.x * 10 - 2) / 10;
	if (v.y > 0)
		cubepos.y = (cord.y * 10 + 12 - win->player->p.y) / 10;
	else
		cubepos.y = (win->player->p.y - cord.y * 10 - 2) / 10;
	return (cubepos);
}

t_cord	assign_cord(int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	return (cord);
}

t_ray	draw_scene(t_window *win, t_point next_pos, t_ray r)
{
	double		plane;
	t_cord		pixel;
	t_vector	plane_v;

	pixel = assign_cord(-1, 0);
	win->player->p = assign_point(next_pos.x, next_pos.y);
	if (check_inside(win, next_pos))
	{
		while (++pixel.x < win->screen->x)
		{
			plane = (2 * (double)pixel.x / 40 - 32) * M_PI / (double)180;
			plane_v = assign_vect(win->player->speed, 0,
					win->player->angle + plane);
			r = raycast(win, 1, win->player->p, plane_v);
			if (r.dist < 2)
				return (r);
			pixel.y = (win->screen->y - win->screen->y / r.dist * 10) / 2 - 1;
			texturess(win, r, pixel);
		}
	}
	return (r);
}
