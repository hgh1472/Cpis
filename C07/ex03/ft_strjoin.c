/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:21:40 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/31 22:51:28 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	cat(char *dest, char *src)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (*(dest + i2) != '\0')
		i2++;
	while (1)
	{
		*(dest + i2) = *(src + i);
		if (*(src + i) == '\0')
			break ;
		i++;
		i2++;
	}
}

void	cat_2(char *str, char **strs, int size, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		cat(str, strs[i]);
		if ((i++) != size - 1)
			cat(str, sep);
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total;
	char	*str;
	int		j;

	if (size == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	j = 0;
	total = 0;
	while (strs[j] != 0 && j < size)
		total += len(strs[j++]);
	str = (char *)malloc(sizeof(char) * (1 + total + (len(sep) * (size - 1))));
	if (str == 0)
		return (0);
	str[0] = '\0';
	cat_2(str, strs, size, sep);
	str[1 + total + (len(sep) * (size - 1))] = '\0';
	return (str);
}
