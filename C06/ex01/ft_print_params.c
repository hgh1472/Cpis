/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:33:52 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/29 22:36:22 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	leng(char *array)
{
	int	i;

	i = 0;
	while (*(array + i) != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = leng(argv[i]);
		write(1, argv[i], j);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
