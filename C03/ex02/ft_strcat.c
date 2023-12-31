/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:00:31 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/24 20:57:52 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (*(dest + i) != '\0')
	{
		i++;
	}
	while (1)
	{
		*(dest + i) = *(src + i2);
		if (*(src + i2) == '\0')
			break ;
		i2++;
		i++;
	}
	return (dest);
}
