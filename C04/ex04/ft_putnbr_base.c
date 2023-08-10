/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:40:14 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/27 09:48:11 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	base_cnt(char *base)
{
	int	i;

	i = 0;
	while (*(base + i) != '\0')
		i++;
	return (i);
}

char	change(char *base, int num)
{
	if (num < 0)
		num *= -1;
	return (*(base + num));
}

int	input(char *temp, int nbr, int base_num, char *base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		temp[i++] = change(base, 0);
	while (nbr != 0)
	{
		temp[i++] = change(base, nbr % base_num);
		nbr /= base_num;
	}
	return (i);
}

int	check_condition(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i) != '\0')
	{
		j = 0;
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		while (j < i)
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	temp[30];
	int		base_num;
	int		i;
	int		p_m;

	if (check_condition(base) == 0)
		return ;
	p_m = 1;
	i = 0;
	base_num = base_cnt(base);
	if (nbr < 0)
		p_m = -1;
	i = input(temp, nbr, base_num, base);
	if (p_m == -1)
		write(1, "-", 1);
	while (--i >= 0)
	{
		write(1, &temp[i], 1);
	}
}
