/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   con.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:20:49 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 18:20:53 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	*number(char *str, int cnt_all, int minus, long long int *temp)
{
	int	cnt;

	cnt = 0;
	temp[0] = 0;
	temp[1] = 0;
	if (cnt_all >= 2)
	{
		temp[0] = -1;
		return (temp);
	}
	while ((*str >= '0' && *str <= '9') && cnt_all < 2)
	{
		temp[1]++;
		temp[0] *= 10;
		if (minus == 1)
			temp[0] -= *str - '0';
		else
			temp[0] += *str - '0';
		str++;
	}
	return (temp);
}

int	arg_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

long long int	ft_atoi(char *str)
{
	long long int	temp[2];
	int				cnt[2];
	int				k;

	cnt[0] = 0;
	cnt[1] = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		cnt[0]++;
		if (*str == '-')
			cnt[1]++;
		str++;
	}
	if (*str == '\0')
		return (-1);
	k = arg_num(str);
	number(str, cnt[0], cnt[1], temp);
	if (temp[1] > 18 || k == 1)
		return (-1);
	return (temp[0]);
}
