/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:20:50 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/02 14:58:34 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
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

void	ft_print_array(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_print_array(par[i].str);
		ft_putnbr(par[i].size);
		ft_print_array(par[i].copy);
		i++;
	}
}
