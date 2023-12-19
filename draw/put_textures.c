/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:33:47 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/09 06:33:50 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_to_img(t_window *win, t_point mesure, mlx_texture_t *txt,
	t_cord cord)
{
	uint8_t			*pixelx;
	uint8_t			*pixeli;
	double			step;
	double			tex_pos;

	step = txt->height / mesure.y;
	tex_pos = 0;
	while (cord.y < (win->screen->y + mesure.y) / 2)
	{
		tex_pos += step;
		if ((int) cord.y < win->screen->y && cord.y > 0
			&& ((int)tex_pos * txt->width + (int)mesure.x) < txt->height
			* txt->width)
		{
			pixelx = &txt->pixels[(((int)tex_pos * txt->width)
					+ (int)mesure.x) * txt->bytes_per_pixel];
			pixeli = &win->img->pixels[(((int)cord.y * win->img->width)
					+ cord.x) * txt->bytes_per_pixel];
			ft_memmove(pixeli, pixelx, txt->bytes_per_pixel);
		}
		cord.y++;
	}
}

void	texturess(t_window *win, t_ray r, t_cord cord)
{
	t_point			cube;
	t_point			mesure;
	mlx_texture_t	*txt;

	cube.x = fmod(r.p.x - 2, 10) / 10;
	cube.y = fmod(r.p.y - 2, 10) / 10;
	mesure.y = win->screen->y / r.dist * 10;
	if (r.side == 'w')
		txt = win->t.we;
	else if (r.side == 'e')
		txt = win->t.ea;
	else if (r.side == 'n')
		txt = win->t.no;
	else
		txt = win->t.so;
	if (r.side == 'w' || r.side == 'e')
		mesure.x = cube.x * txt->width;
	else if (r.side == 'n' || r.side == 's')
		mesure.x = cube.y * txt->width;
	texture_to_img(win, mesure, txt, cord);
}
