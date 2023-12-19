/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:17:00 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/02 18:17:03 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_point	assign_point(double x, double y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point	assign_int_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

double	angle_adjast(double angle, char sign)
{
	if (angle <= 0)
		angle += M_PI * 2;
	if (sign == '-')
		angle -= M_PI / 180;
	if (sign == '+')
		angle += M_PI / 180;
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	return (angle);
}

t_vector	assign_vect(double vx, double vy, double angle)
{
	t_vector	vec;

	vec.x = vx;
	vec.y = vy;
	vec = rotation_vect(vec, angle_adjast(angle, '*'));
	return (vec);
}

t_point	pos_adjast(t_window *win, t_point pos)
{
	if (pos.x < 5)
		pos.x = win->map->len * 10;
	else if (pos.x > win->map->len * 10)
		pos.x = 6;
	if (pos.y < 5)
		pos.y = win->map->wide * 10;
	else if (pos.y > win->map->wide * 10)
		pos.y = 6;
	return (pos);
}
