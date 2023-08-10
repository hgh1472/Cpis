/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:08:40 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/01 08:43:33 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	length(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (length(src) + 1));
	if (copy == 0)
		return (0);
	while (*(src + i))
	{
		*(copy + i) = *(src + i);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
