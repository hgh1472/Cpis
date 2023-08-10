/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:53:53 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/25 19:47:57 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	len_s(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	leng_dest;
	unsigned int	leng_src;

	leng_dest = len_s(dest);
	leng_src = len_s(src);
	i = 0;
	if (size <= leng_dest)
		return (size + leng_src);
	while (src[i] != '\0' && i < size - leng_dest - 1)
	{
		dest[leng_dest + i] = src[i];
		i++;
	}
	dest[leng_dest + i] = '\0';
	return (leng_dest + leng_src);
}
