/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:50:17 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/27 09:48:05 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check_con(char *base)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (*(base + i) != '\0')
	{
		c = *(base + i);
		j = 0;
		while (j < i)
		{
			if (*(base + (j++)) == c)
				return (0);
		}
		if (c == '+' || c == '-')
			return (0);
		if ((c >= 9 && c <= 13) || c == 32)
			return (0);
		i++;
	}
		i++;
	if (i < 2)
		return (0);
	return (1);
}

int	level_check(char c, char *base)
{
	int	i;
	int	ch;

	i = 0;
	ch = 0;
	while (*(base + i) != '\0')
	{
		if (*(base + i) == c)
			ch = 1;
		i++;
	}
	if ((c >= 9 && c <= 13) || c == 32)
		return (0);
	else if (c == '+' || c == '-')
		return (1);
	else if (ch == 1)
		return (2);
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (3);
	return (4);
}

int	cha_to_num(char c, char *base)
{
	int	i;

	i = 0;
	while (*(base + i) != '\0')
	{
		if (c == *(base + i))
			break ;
		i++;
	}
	return (i);
}

int	chan(char *tmp, char *base, int minus)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	j = 0;
	num = 0;
	while (*(base + j) != '\0')
		j++;
	while (*(tmp + i) != '\0')
	{
		num *= j;
		if (minus == 1)
			num += cha_to_num(*(tmp + i), base);
		else if (minus == -1)
			num -= cha_to_num(*(tmp + i), base);
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		level;
	char	num[30];
	int		minus_cnt;
	int		index;

	index = 0;
	i = 0;
	level = 0;
	minus_cnt = 1;
	while (*(str + i) != '\0' && check_con(base) == 1)
	{
		if (level_check(*(str + i), base) < level && level != 2)
			return (0);
		else if (level_check(*(str + i), base) != level && level == 2)
			break ;
		level = level_check(*(str + i), base);
		if (*(str + i) == '-')
			minus_cnt = minus_cnt * (-1);
		if (level_check(*(str + i), base) == 2)
			num[index++] = *(str + i);
		i++;
	}
	num[index] = '\0';
	return (chan(num, base, minus_cnt));
}
