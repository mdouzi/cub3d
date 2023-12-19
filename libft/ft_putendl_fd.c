/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:45:39 by ohachami          #+#    #+#             */
/*   Updated: 2022/10/23 01:33:20 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	next_line;

	next_line = '\n';
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, &next_line, 1);
}
