/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:13:43 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/01 18:14:48 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (*(s1 + i) != '\0' || *(s2 + i) != '\0')
	{
		a = (unsigned char)*(s1 + i);
		b = (unsigned char)*(s2 + i);
		if (a != b)
			return ((int)(a - b));
		i++;
	}
	return ((int)(a - b));
}
