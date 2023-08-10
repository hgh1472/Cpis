/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:40:22 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/23 09:19:52 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print8(char a[], int n)
{
	write(1, a, n);
	if (a[0] != '9' - (n - 1))
		write(1, ", ", 2);
}

void	comb(char a[], int n, int r, int q)
{
	if (r == 0)
	{
		print8(a, q);
		return ;
	}
	else if (n < r)
		return ;
	else
	{
		a[q - r] = '9' - (n - 1);
		comb(a, n - 1, r - 1, q);
		comb(a, n - 1, r, q);
	}
}

void	ft_print_combn(int n)
{
	char	a[10];

	comb(a, 10, n, n);
}
