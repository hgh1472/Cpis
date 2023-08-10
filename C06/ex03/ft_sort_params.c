/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:36:55 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/31 12:26:49 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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

void	gv_print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*tmp;
	int		j;

	i = 1;
	tmp = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (compare(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	gv_print(argc, argv);
	return (0);
}
