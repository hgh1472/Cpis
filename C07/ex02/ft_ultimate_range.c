/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:30:57 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/31 22:53:04 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (max <= min)
	{
		range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * ((max - min) + 1));
	if (*range == 0)
		return (-1);
	while (i < max - min)
	{
		*(*(range) + i) = min + i;
		i++;
	}
	*(*(range) + i) = '\0';
	return (i);
}
