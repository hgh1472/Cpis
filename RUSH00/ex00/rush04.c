/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhwa <changhwa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:46:36 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/26 09:05:43 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print(int nx, int ny, int x, int y)
{
	while (nx <= x)
	{
		if (ny == 1 || ny == y)
		{
			if (nx > 1 && nx < x)
				ft_putchar('B');
			else if (((nx * ny == x) && nx > 1) || ((ny * nx == y) && ny > 1))
				ft_putchar('C');
			else
				ft_putchar('A');
		}
		else
		{
			if (nx == 1 || nx == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		nx++;
	}
}

void	rush(int x, int y)
{
	int	nx;
	int	ny;

	nx = 1;
	ny = 1;
	if (x <= 0 || y <= 0)
	{
		ft_putchar('E');
		ft_putchar('\n');
		return ;
	}
	while (ny <= y)
	{
		print(nx, ny++, x, y);
		ft_putchar('\n');
	}
}
