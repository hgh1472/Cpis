/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:29:17 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/23 16:41:38 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_both_ends(int x, int d_x, int flag)
{
	if (flag == 0)
	{
		if (x == 1)
			ft_putchar('/');
		else if (x == d_x)
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
	else
	{
		if (x == 1)
			ft_putchar('\\');
		else if (x == d_x)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
}

void	check(int x, int y, int d_x, int d_y)
{
	while (x <= d_x)
	{
		if (y == 1)
			print_both_ends(x, d_x, 0);
		else if (y == d_y)
			print_both_ends(x, d_x, 1);
		else
		{
			if (x == 1 || x == d_x)
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		x++;
	}
}

void	rush(int d_x, int d_y)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (d_x == 0 || d_y == 0)
	{
		ft_putchar(' ');
		return ;
	}
	while (y <= d_y)
	{
		check(x, y, d_x, d_y);
		y++;
		ft_putchar('\n');
	}
}
