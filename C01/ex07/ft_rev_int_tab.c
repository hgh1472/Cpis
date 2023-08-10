/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:38:21 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/22 21:50:33 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	index;

	index = 0;
	while (size / 2 > index)
	{
		tmp = *(tab + index);
		*(tab + index) = *(tab + (size - index - 1));
		*(tab + (size - index - 1)) = tmp;
		index++;
	}
}
