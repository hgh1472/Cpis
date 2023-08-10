/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:50:35 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/01 09:09:40 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		arrlen(char *array);
int		push(char *array, char *base_to, int num);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		count_base(int num, char *base);

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i) != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (*(base + j) == *(base + i))
				return (0);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		if ((*(base + i) >= 9 && *(base + i) <= 13) || *(base + i) == 32)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	check_inbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	toten(char *str, char *base_from, int minus)
{
	int	n;
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	n = arrlen(base_from);
	while (str[i] != '\0')
	{
		ret *= n;
		if (minus == -1)
			ret -= check_inbase(str[i], base_from);
		else
			ret += check_inbase(str[i], base_from);
		i++;
	}
	return (ret);
}

char	*tentobase(int num, char *base_to)
{
	int		n;
	char	*ret;
	char	array[40];
	int		i;
	int		j;

	j = 0;
	n = arrlen(base_to);
	ret = (char *)malloc(sizeof(char) * (1 + count_base(num, base_to)));
	if (ret == 0)
		return (ret);
	if (num < 0)
		ret[j++] = '-';
	i = push(array, base_to, num);
	while (i-- > 0)
		ret[j++] = array[i];
	ret[j] = '\0';
	return (ret);
}

int	count_base(int num, char *base)
{
	int	n;
	int	i;

	i = 0;
	n = arrlen(base);
	while (num != 0)
	{
		num /= n;
		i++;
	}
	if (num < 0)
		i++;
	return (i);
}
