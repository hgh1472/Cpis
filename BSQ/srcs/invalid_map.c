/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:26:28 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/09 20:30:09 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	identical_check(char *index)
{
	if (index[0] == index[1])
		return (0);
	if (index[0] == index[2])
		return (0);
	if (index[1] == index[2])
		return (0);
	return (1);
}

int	print_check(char *index)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(index[i] >= 32 && index[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

int	map_num(char *buff, t_map *s_map, int i, int *j)
{
	int	num;

	num = 0;
	while (*j < i)
	{
		if (!(buff[*j] >= '0' && buff[*j] <= '9'))
			return (0);
		num = num * 10 + buff[*j] - '0';
		*j += 1;
	}
	s_map->row = num;
	return (num);
}

int	fir_format_check(char *buff, t_map *s_map)
{
	int		i;
	char	index[3];
	int		j;

	j = 0;
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (i < 4)
		return (0);
	while (j < 3)
		index[j++] = buff[--i];
	j = 0;
	s_map->row = map_num(buff, s_map, i, &j);
	if (s_map->row == 0)
		return (0);
	if (!identical_check(index) || !print_check(index))
		return (0);
	return (j);
}

int	invalid(char *buff, t_map *m)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = fir_format_check(buff, m);
	if (cnt == 0)
		return (0);
	while (i++ < cnt)
		buff++;
	m->empty = *(buff++);
	m->obs = *(buff++);
	m->fill = *(buff++);
	buff++;
	if (line_check(buff, m) == 0)
		return (0);
	return (1);
}
