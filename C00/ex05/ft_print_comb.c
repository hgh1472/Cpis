/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:17:49 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/22 17:44:44 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(int n)
{
	int	first;
	int	second;
	int	third;

	first = n / 100;
	second = n % 100 / 10;
	third = n % 10;
	if (first < second && second < third)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	print(char a[], int n)
{
	write(1, a, 3);
	if (n != 789)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int		number;
	char	a[3];

	number = 12;
	while (number <= 789)
	{
		a[0] = '0' + number / 100;
		a[1] = '0' + number % 100 / 10;
		a[2] = '0' + number % 10;
		if (check(number) == 1)
		{
			print(a, number);
		}
		number++;
	}
}
