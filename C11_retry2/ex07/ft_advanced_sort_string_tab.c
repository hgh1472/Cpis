/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_sorting_tab.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:57:06 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/07 17:22:04 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*tmp;
	int		j;
	int		len;

	i = 0;
	tmp = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
