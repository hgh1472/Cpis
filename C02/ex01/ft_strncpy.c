/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:44:45 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/26 10:49:23 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	index;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		if (*(src + i) == '\0')
		{
			index = n - i;
			while (index > 0)
			{
				*(dest + i) = '\0';
				index--;
				i++;
			}
		}
		i++;
	}
	return (dest);
}


