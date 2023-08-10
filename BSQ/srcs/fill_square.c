/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:45:12 by sehyupar          #+#    #+#             */
/*   Updated: 2023/08/09 15:50:10 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	fill_square(char **map, t_square *s, t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < s->size)
	{
		while (x < s->size)
		{
			map[s->y - y][s->x - x] = m->fill;
			x++;
		}
		x = 0;
		y++;
	}
}
