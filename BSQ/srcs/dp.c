/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:47:38 by sehyupar          #+#    #+#             */
/*   Updated: 2023/08/09 20:34:02 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	find_min(int **dp, int x, int y)
{
	int	min;

	min = dp[y - 1][x - 1];
	if (dp[y][x - 1] < min)
		min = dp[y][x - 1];
	if (dp[y - 1][x] < min)
		min = dp[y - 1][x];
	return (min);
}

void	update_square(t_square *s, int max, int x, int y)
{
	s->size = max;
	s->x = x;
	s->y = y;
}

void	mark_map(int **dp, char **map, t_map *m, t_square *s)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < m->row)
	{
		while (x < m->col)
		{
			if (map[y][x] == m->obs)
				dp[y][x] = 0;
			else if (x == 0 || y == 0)
				dp[y][x] = 1;
			else
				dp[y][x] = find_min(dp, x, y) + 1;
			if (dp[y][x] > s->size)
				update_square(s, dp[y][x], x, y);
			x++;
		}
		y++;
		x = 0;
	}
}

int	dp(char **map, t_map *m, t_square *s)
{
	int			x;
	int			y;
	int			**dp;

	x = 0;
	y = 0;
	dp = (int **)malloc(sizeof(int *) * m->row);
	if (dp == 0)
		return (0);
	while (y < m->row)
	{
		dp[y] = (int *)malloc(sizeof(int) * m->col);
		if (dp[y] == 0)
		{
			free_dp(dp, y);
			return (0);
		}
		y++;
	}
	s->size = 0;
	mark_map(dp, map, m, s);
	y = 0;
	free_dp(dp, m->row);
	return (1);
}
