/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:05:12 by sehyupar          #+#    #+#             */
/*   Updated: 2023/08/09 20:34:21 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	free_map_m(t_map *m, char **array)
{
	free_array(array, m->row);
	free(m);
}

void	print_map(char **map, t_map *m)
{
	int	i;

	i = 0;
	while (i < m->row)
	{
		write(1, map[i++], m->col);
		write(1, "\n", 1);
	}
}

void	find_square(char **map, t_map *m)
{
	t_square	*s;
	int			i;

	i = 0;
	s = (t_square *)malloc(sizeof(t_square));
	if (s == 0)
	{
		free_map_m(m, map);
		return ;
	}
	if (!dp(map, m, s))
	{
		free_map_m(m, map);
		free(s);
		return ;
	}
	fill_square(map, s, m);
	print_map(map, m);
	free(s);
	free_map_m(m, map);
}
