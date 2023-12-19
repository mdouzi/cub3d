/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 03:58:32 by ohachami          #+#    #+#             */
/*   Updated: 2023/11/18 03:58:36 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	check_name(int fd, char *file)
{
	int	i;

	if (fd < 1)
		ft_exit("Error No file wrong.\n");
	i = ft_strlen(file);
	if (i < 5)
		ft_exit("Error No file wrong.\n");
	if (file[i - 4] != '.' || file[i - 3] != 'c' || file[i - 2] != 'u' || file[i
			- 1] != 'b')
		ft_exit("Error Found wrong line length, Exiting...\n");
}

void	check_lines(char *file)
{
	char	*line;
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	check_name(fd, file);
	line = get_next_line(fd);
	len = 0;
	while (line != NULL)
	{
		if (line[0] != '\n')
			len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (len < 9)
		ft_exit("Error need more information, Exiting...\n");
}
