/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:41:27 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/02 13:10:47 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	copystring(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_st;
	int			i;

	i = 0;
	s_st = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (s_st == 0)
		return (0);
	while (i < ac)
	{
		s_st[i].size = length(av[i]);
		s_st[i].str = av[i];
		s_st[i].copy = (char *)malloc((sizeof(char) * (length(av[i]) + 1)));
		if (s_st[i].copy == 0)
			return (0);
		copystring(s_st[i].copy, av[i]);
		i++;
	}
	s_st[i].str = 0;
	return (s_st);
}
