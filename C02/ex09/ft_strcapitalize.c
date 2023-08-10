/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:05:36 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/25 10:24:24 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	c_a(char c)
{
	int	i;

	i = 0;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		i = 1;
	if (c >= '0' && c <= '9')
		i = 1;
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((c_a(*(str + i)) == 1 && c_a(*(str + i - 1)) == 0))
		{
			if ((*(str + i) >= 'a' && *(str + i) <= 'z'))
				*(str + i) = *(str + i) - 'a' + 'A';
		}
		else if (c_a(*(str + i)) == 1)
		{
			if (*(str + i) >= 'A' && *(str + i) <= 'Z')
				*(str + i) = *(str + i) - 'A' + 'a';
		}
		i++;
	}
	return (str);
}
