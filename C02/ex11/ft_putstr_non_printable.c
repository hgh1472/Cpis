/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:24:47 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/25 10:36:36 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	pt_f(unsigned char c, char *str)
{
	char	d_char;
	int		div;

	div = c / 16;
	d_char = *(str + div);
	write(1, &d_char, 1);
}

void	pt_s(unsigned char c, char *str)
{
	char	m_char;
	int		mod;

	mod = c % 16;
	m_char = *(str + mod);
	write(1, &m_char, 1);
}

int	c_printable(unsigned char a)
{
	if (a >= 32 && a <= 126)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (*(str + i) != '\0')
	{
		c = *(str + i);
		if (c_printable(c) == 0)
		{
			write(1, "\\", 1);
			pt_f(c, "0123456789abcdef");
			pt_s(c, "0123456789abcdef");
		}
		else
			write(1, (str + i), 1);
		i++;
	}
}
