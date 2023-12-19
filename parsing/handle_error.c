/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:56:49 by mdouzi            #+#    #+#             */
/*   Updated: 2023/11/17 23:52:46 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	exit_all(t_map *g, char *str)
{
	ft_putstr_fd(str, 2);
	free_tab(g->mapo);
	free_tab(g->full_file);
	free(g->player);
	exit(1);
}

void	exit_map_error(t_map *g, char *str)
{
	ft_putstr_fd(str, 2);
	free(g->map_line);
	free(g->split_line);
	free(g->mapo);
	free(g->full_file);
	exit(1);
}

void	free_txt(t_map *g, char *str)
{
	free(g->so);
	free(g->we);
	free(g->no);
	free(g->ea);
	exit_all(g, str);
}

void	exit_from_start(t_window *win)
{
	(void)win;
}
