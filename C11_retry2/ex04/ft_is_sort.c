/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:40:45 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/07 11:03:49 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	cnt[2];

	i = 0;
	cnt[0] = 0;
	cnt[1] = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			cnt[0]++;
		else if ((*f)(tab[i], tab[i + 1]) > 0)
			cnt[1]++;
		else
		{
			cnt[0]++;
			cnt[1]++;
		}
		i++;
	}
	if (cnt[0] == i || cnt[1] == i)
		return (1);
	else
		return (0);
}
