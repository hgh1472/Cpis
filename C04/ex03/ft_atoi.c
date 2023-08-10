/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:15:03 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/27 09:37:18 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (0);
	else if (c == '+' || c == '-')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (3);
	return (4);
}

int	pr_num(char *num, int cnt, int p_m)
{
	int	number;
	int	index;

	index = 0;
	number = 0;
	while (index < cnt)
	{
		number *= 10;
		number += (int)(num[index++] - '0');
	}
	return (p_m * number);
}

int	ft_atoi(char *str)
{
	int		i;
	int		index;
	char	num[30];
	int		level;
	int		p_m;

	level = 0;
	i = 0;
	index = 0;
	p_m = 1;
	while (*(str + i) != '\0')
	{
		if (check(*(str + i)) < level && level != 2)
			return (0);
		else if (check(*(str + i)) != level && level == 2)
			break ;
		level = check(*(str + i));
		if (*(str + i) == '-')
			p_m = p_m * (-1);
		if (check(*(str + i)) == 2)
			num[index++] = *(str + i);
		i++;
	}
	return (pr_num(num, index, p_m));
}
