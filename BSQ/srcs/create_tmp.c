/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:33:06 by sehyupar          #+#    #+#             */
/*   Updated: 2023/08/09 22:42:23 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	init_buffer(char *buf, int buf_size)
{
	int	i;

	i = 0;
	while (i < buf_size)
		buf[i++] = 0;
}

void	create_tmp(void)
{
	char	buf[1];
	int		fd;
	int		n;

	fd = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	while (1)
	{
		init_buffer(buf, 1);
		n = read(0, buf, 1);
		write(fd, buf, 1);
		if (*buf == '\0')
			break ;
	}
	close(fd);
}
