/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:56:31 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 20:35:49 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare(char *str1, char *str);

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	tmp = 0;
	while (tab[i + 1] != 0)
	{
		j = i + 1;
		while (tab[j] != 0)
		{
			if (compare(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	compare(char *str1, char *str2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (*(str1 + i) != '\0' || *(str2 + i) != '\0')
	{
		a = (unsigned char)*(str1 + i);
		b = (unsigned char)*(str2 + i);
		if (a != b)
			return ((int)(a - b));
		i++;
	}
	return ((int)(a - b));
}
