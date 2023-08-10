/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:26:44 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/30 11:13:46 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	row_check5(int *array, int left, int right)
{
	int	max[2];
	int	cnt[3];

	cnt[2] = 1;
	cnt[0] = 1;
	cnt[1] = 1;
	max[0] = array[0];
	max[1] = array[4];
	while (cnt[2] < 5)
	{
		if (max[0] < array[cnt[2]])
		{
			max[0] = array[cnt[2]];
			cnt[0]++;
		}
		if (max[1] < array[4 - cnt[2]])
		{
			max[1] = array[4 - cnt[2]];
			cnt[1]++;
		}
		cnt[2]++;
	}
	if (left == cnt[0] && right == cnt[1])
		return (1);
	return (0);
}

int	c_ch5(int **array, int up, int down, int index)
{
	int	max[2];
	int cnt[3];

	cnt[0] = 1;
	cnt[1] = 1;
	cnt[2] = 1;
	max[0] = array[0][index];
	max[1] = array[4][index];
	while (cnt[2] < 5)
	{
		if (max[0] < array[cnt[2]][index])
		{
			max[0] = array[cnt[2]][index];
			cnt[0]++;
		}
		if (max[1] < array[4 - cnt[2]][index])
		{
			max[1] = array[4 - cnt[2]][index];
			cnt[1]++;
		}
		cnt[2]++;
	}
	if (up == cnt[0] && down == cnt[1])
		return (1);
	return (0);
}

int	check5(int **array, int **index)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < 5)
	{
		if (row_check5(array[row], index[1][row], index[1][row + 5]) == 0)
			return (0);
		row++;
	}
	while (column < 5)
	{
		if (c_ch5(array, index[0][column], index[0][column + 5], column) == 0)
			return (0);
		column++;
	}
	return (1);
}
