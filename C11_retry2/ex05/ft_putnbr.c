/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:55:40 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 19:56:06 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	insert(char a[], int n, int index)
{
	if (n == 0)
		return (0);
	while (n != 0)
	{
		a[index] = '0' + n % 10;
		n /= 10;
		index++;
	}
	return (index - 1);
}

void	print7(char number[], int flag, int index)
{
	if (flag == 1)
		write(1, "-", 1);
	while (index >= 0)
	{
		write(1, &number[index], 1);
		index--;
	}
}

void	ft_putnbr(int nb)
{
	int		index;
	char	number[11];
	int		flag;

	index = 0;
	flag = 0;
	number[0] = '0';
	if (nb == -2147483648)
	{
		number[0] = '0' + (nb % 10 * (-1));
		nb = nb / 10 * (-1);
		index++;
		flag = 1;
	}
	if (nb < 0)
	{
		flag = 1;
		nb *= -1;
	}
	index = insert(number, nb, index);
	print7(number, flag, index);
	write(1, "\n", 1);
}
