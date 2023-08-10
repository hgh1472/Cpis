/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:08:39 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/07 11:05:19 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		plus(int num1, int num2);
int		minus(int num1, int num2);
int		mul(int num1, int num2);
int		div(int num1, int num2);
int		mod(int num1, int num2);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_op(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (2);
	if (c == '*')
		return (3);
	if (c == '/')
		return (4);
	if (c == '%')
		return (5);
	return (0);
}

int	valid_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) != 1 || check_op(argv[2][0]) == 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int	byzero(int *number, char op)
{
	if (number[1] == 0)
	{
		if (op == '/')
		{
			write(1, "Stop : division by zero\n", 24);
			return (1);
		}
		else if (op == '%')
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	number[2];
	int	(*f[5])(int, int);
	int	ans;
	int	op;

	f[0] = plus;
	f[1] = minus;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	if (valid_argv(argc, argv) == 0)
		return (0);
	number[0] = ft_atoi(argv[1]);
	number[1] = ft_atoi(argv[3]);
	if (byzero(number, argv[2][0]) == 1)
		return (0);
	op = check_op(argv[2][0]);
	ans = f[op - 1](number[0], number[1]);
	ft_putnbr(ans);
	return (0);
}
