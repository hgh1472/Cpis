/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:17:56 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/01 10:15:31 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		check_base(char *base);
int		toten(char *arr, char *base, int minus);
char	*tentobase(int num, char *base_to);
int		check_inbase(char c, char *base);
int		count_base(int num, char *base);

int	arrlen(char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

int	push(char *array, char *base_to, int num)
{
	int	i;
	int	n;

	n = arrlen(base_to);
	i = 0;
	if (num == 0)
		array[i++] = base_to[0];
	while (num != 0)
	{
		if (num < 0)
			array[i++] = base_to[-(num % n)];
		else
			array[i++] = base_to[num % n];
		num /= n;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		minus;
	char	array[40];
	int		j;
	char	*ans;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	minus = 1;
	i = 0;
	j = 0;
	while ((*(nbr + i) >= 9 && *(nbr + i) <= 13) || *(nbr + i) == 32)
		i++;
	while (*(nbr + i) == '+' || *(nbr + i) == '-')
	{
		if (*(nbr + i) == '-')
			minus *= -1;
		i++;
	}
	while (check_inbase(*(nbr + i), base_from) != -1)
		array[j++] = *(nbr + (i++));
	array[j] = '\0';
	ans = tentobase(toten(array, base_from, minus), base_to);
	return (ans);
}
