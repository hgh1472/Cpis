/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_ch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:21:49 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 18:28:34 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

long long int	ft_atoi(char *str);

char	**input_check(int argc, char **argv)
{
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * 3);
	if (temp == 0)
		return (0);
	if (argc == 1 || argc == 2)
	{
		if (argc == 1)
			temp[1] = "-1";
		else
			temp[1] = argv[1];
		temp[0] = "./numbers.dict";
	}
	if (argc == 3)
	{
		temp[0] = argv[1];
		temp[1] = argv[2];
	}
	return (temp);
}

int	dict_size_check(char **temp)
{
	int		fd;
	char	buff[1];
	int		cnt;

	cnt = 0;
	fd = open(temp[0], O_RDONLY);
	if (0 < fd)
	{
		while (read(fd, buff, 1))
			cnt++;
		close(fd);
	}
	if (cnt == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (cnt);
}

int	arg_check(int argc, char **temp)
{
	long long int	num;

	if (argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	num = ft_atoi(temp[1]);
	if (num < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
