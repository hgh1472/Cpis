/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:30:35 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/09 20:32:33 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft.h"

char	**buff_to_array(char *buff, int line, int col)
{
	char	**array;
	int		i;
	int		j;

	j = 0;
	i = 0;
	array = (char **)malloc(sizeof(char *) * (line + 1));
	if (array == 0)
		return (0);
	while (i < line)
	{
		j = 0;
		array[i] = (char *)malloc(sizeof(char) * (col + 1));
		if (array[i] == 0)
		{
			free_array(array, i);
			return (0);
		}
		while (j < col)
			array[i][j++] = *(buff++);
		i++;
		buff++;
	}
	array[i] = 0;
	return (array);
}

char	*buff_in(char *temp, int index)
{
	char	*buff;
	int		fd;

	fd = open(temp, O_RDONLY);
	if (index == 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * (index + 1));
	if (buff == 0)
		return (0);
	if (0 < fd)
	{
		read(fd, buff, index + 1);
		close(fd);
		buff[index] = '\0';
	}
	else
		return (0);
	return (buff);
}

int	size_check(char *temp)
{
	int		fd;
	char	buff[1];
	int		cnt;

	cnt = 0;
	fd = open(temp, O_RDONLY);
	if (0 < fd)
	{
		while (read(fd, buff, 1))
			cnt++;
		close(fd);
	}
	else
		return (0);
	return (cnt);
}

void	process(char *argv)
{
	char	**array;
	char	*buff;
	t_map	*s_map;
	int		i;

	i = 0;
	s_map = (t_map *)malloc(sizeof(t_map));
	if (!s_map)
		return ;
	buff = buff_in(argv, size_check(argv));
	if (buff == 0)
		return (free_map_with_err(s_map));
	if (invalid(buff, s_map) == 0)
		return (free_with_error(s_map, buff));
	while (buff[i] != '\n')
		i++;
	i++;
	array = buff_to_array((buff + i), s_map->row, s_map->col);
	if (array == 0)
	{
		free_st_buf(s_map, buff);
		return ;
	}
	free(buff);
	find_square(array, s_map);
}
