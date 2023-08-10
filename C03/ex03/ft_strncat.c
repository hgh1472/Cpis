/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:59:25 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/25 19:31:16 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	i2 = 0;
	while (*(dest + i) != '\0')
		i++;
	while (i2 < nb && *(src + i2) != '\0')
	{
		*(dest + i) = *(src + i2);
		i++;
		i2++;
	}
	*(dest + i) = '\0';
	return (dest);
}
