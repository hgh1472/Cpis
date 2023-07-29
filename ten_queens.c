/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_queens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgh1472 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:58:54 by hgh1472           #+#    #+#             */
/*   Updated: 2023/07/29 14:59:03 by hgh1472          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int	valid(char *array, int x, int y)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (j < y)
	{
		if ((array[j] - ('0' + x)) == j - y || '0' + x - array[j] == j - y)
		{
			return (0);
		}
		j++;
	}
	while (i < y)
	{
		if (*(array + i) == '0' + x)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
void	ten_queens(char *array, int x, int y)
{
	if (valid(array, x, y) == 1)
	{
		array[y] = '0' + x;
		if (y == 9)
		{
			write(1, array, 10);
			write(1, "\n", 1);
			return ;
		}
		ten_queens(array, 0, y + 1);
	}
	if (x < 9)
		ten_queens(array, x + 1, y);
}
void	ft_ten_queens_puzzle(void)
{
	char	array[10];
	ten_queens(array, 0, 0);
}
int main()
{
	ft_ten_queens_puzzle();
	return 0;
}







