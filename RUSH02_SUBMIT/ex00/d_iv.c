/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_iv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:20:37 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 18:20:40 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	make_num(char *buff, long long int *cnt, int *flag);

int	initial_key_check(long long int num)
{
	long long int	initial_key[105];
	int				i;

	i = 0;
	while (i <= 20)
	{
		initial_key[i] = i;
		i++;
	}
	while (i <= 28)
	{
		initial_key[i] = initial_key[i - 1] + 10;
		i++;
	}
	initial_key[i++] = 1000;
	initial_key[i++] = 1000000;
	initial_key[i++] = 1000000000;
	i = 0;
	while (i < 32)
	{
		if (initial_key[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	format_check(char *buff, int flag)
{
	while (*buff <= 32 || *buff == '+' || *buff == '-')
		buff++;
	while (*buff >= '0' && *buff <= '9')
	{
		buff++;
		flag = 1;
	}
	while (*buff == ' ')
		buff++;
	while (*buff == ':' && flag == 1)
	{
		buff++;
		flag = 2;
	}
	while (*buff == ' ' && flag == 2)
		buff++;
	while (*buff != '\n' && flag == 2 && *buff != '\0')
	{
		if (*buff >= 32 && *buff <= 126)
			flag = 3;
		buff++;
	}
	if (flag != 3)
		return (0);
	return (1);
}

int	valid_check(char **buff, long long int *num, long long int *cnt)
{
	int	flag;

	flag = 0;
	if (**buff == '\n')
		return (1);
	if (!format_check(*buff, 0))
		return (0);
	*num = make_num(*buff, cnt, &flag);
	if (*num == -1)
		return (0);
	if (flag == 0)
	{
		while (**buff != '\n')
			*buff = *buff + 1;
	}
	return (1);
}

char	*colon_check(char *buff)
{
	while (*buff != ':')
		buff++;
	buff++;
	return (buff);
}

char	*enter_check(char *buff)
{
	while (*buff != '\n')
		buff++;
	return (buff);
}
