/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:20:14 by mdouzi            #+#    #+#             */
/*   Updated: 2023/11/17 22:33:26 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty(char c)
{
	if (c == '\0')
		return (1);
	else
		return (0);
}

int	not_map(char c)
{
	if (c == '0' || c == '1')
		return (1);
	else
		return (0);
}

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	free_all(t_window *win)
{
	int	i;

	i = -1;
	while (win->map->mapo[++i])
		free(win->map->mapo[i]);
	free(win->map->mapo);
	if (win->t.ea)
		mlx_delete_texture(win->t.ea);
	if (win->t.so)
		mlx_delete_texture(win->t.so);
	if (win->t.we)
		mlx_delete_texture(win->t.we);
	if (win->t.no)
		mlx_delete_texture(win->t.no);
	if (win->img)
		mlx_delete_image(win->mlx_ptr, win->img);
	if (win->mlx_ptr)
		mlx_terminate(win->mlx_ptr);
	free(win->player);
	free(win->screen);
	free(win);
}

void	get_last_n_line(char *line, char **kep)
{
	*kep = ft_strjoin2(*kep, line);
	*kep = ft_strjoin2(*kep, "\n");
}
