/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:24:32 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/09 20:25:30 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	in_index(char c, t_map *m)
{
	if (c != m->empty && c != m->obs)
		return (0);
	return (1);
}

int	check_line(char **buff, t_map *m, int *col)
{
	while (**buff != '\n' && **buff)
	{
		if (!in_index(**buff, m))
			return (0);
		*col += 1;
		(*buff)++;
	}
	if (**buff != '\n' || *col == 0)
		return (0);
	return (1);
}

int	line_check(char *buff, t_map *m)
{
	int	col;
	int	flag;
	int	cnt;

	cnt = 0;
	flag = 0;
	while (*buff)
	{
		col = 0;
		if (!check_line(&buff, m, &col))
			return (0);
		cnt++;
		if ((flag++) == 0)
			m->col = col;
		if (col != m->col)
			return (0);
		buff++;
	}
	if (cnt != m->row)
		return (0);
	return (1);
}
