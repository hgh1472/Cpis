/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:29:51 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/25 14:45:44 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		*(dest + i) = *(src + i);
		if (*(src + i) == '\0')
			break ;
		i++;
	}
	return (dest);
}