/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:07:41 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/25 09:52:29 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned char	c_s(long long int num, char *str)
{
	return (*(str + num));
}

void	str_pr(void *adrs, unsigned int i)
{
	unsigned int	index;
	unsigned char	a;

	index = 0;
	write(1, " ", 1);
	while (index < i)
	{
		a = *((unsigned char *)(adrs + index));
		if (a >= 32 && a < 127)
			write(1, &a, 1);
		else
			write(1, ".", 1);
		index++;
	}
	write(1, "\n", 1);
}

void	p_a(unsigned char temp[], char *str, long long int cnt, void *adrs)
{
	temp[2 * cnt] = *(unsigned char *)(adrs + cnt);
	temp[2 * cnt + 1] = c_s((int)temp[2 * cnt] % 16, str);
	temp[2 * cnt] = c_s((int)temp[2 * cnt] / 16, str);
	write(1, &temp[2 * cnt], 2);
}

void	print(void *adrs, int i, long long int adre)
{
	unsigned char			temp[40];
	int						cnt;
	unsigned char			a[20];

	cnt = 0;
	while (adre != 0)
	{
		a[cnt++] = c_s(adre % 16, "0123456789abcdef");
		adre /= 16;
	}
	write(1, "0000000000000000", 16 - cnt);
	while (cnt >= 0)
		write(1, &a[--cnt], 1);
	write(1, ":", 1);
	while (16 > ++cnt)
	{
		if (cnt % 2 == 0)
			write(1, " ", 1);
		if (cnt >= i)
			write(1, "  ", 2);
		else
			p_a(temp, "0123456789abcdef", cnt, adrs);
	}
	str_pr(adrs, i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	div;
	unsigned int	mod;
	long long int	adre;
	void			*addr2;

	addr2 = addr;
	div = size / 16;
	mod = size % 16;
	while (div > 0)
	{
		adre = (long long int)(addr2);
		print(addr2, 16, adre);
		div--;
		addr2 = addr2 + 16;
	}
	if (mod != 0)
	{
		adre = (long long int)(addr2);
		print(addr2, mod, adre);
	}
	return (addr);
}
