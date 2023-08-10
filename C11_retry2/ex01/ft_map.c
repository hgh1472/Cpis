/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:42:36 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/02 14:49:18 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * (length + 1));
	while (i < length && tab[i])
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
