/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:16:47 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/31 22:52:55 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	i = 0;
	if (max <= min)
		return (0);
	array = (int *)malloc(sizeof(int) * ((max - min) + 1));
	if (array == 0)
		return (array);
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	array[i] = '\0';
	return (array);
}
