/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:23:26 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/09 20:40:49 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**array;

	i = 0;
	array = 0;
	if (argc == 1)
	{
		create_tmp();
		process("tmp.txt");
	}
	while (++i < argc && argc != 1)
	{
		if (i != 1)
			write(1, "\n", 1);
		process(argv[i]);
	}
	return (0);
}
