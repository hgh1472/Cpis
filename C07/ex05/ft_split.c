/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:02:18 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/01 09:12:11 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	c_sep(char c, char *charset)
{
	int	i;

	i = 0;
	if (charset == 0)
		return (0);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	jump(char *str, char *sep, int i, int index)
{
	if (i == 0)
	{
		while (str[index])
		{
			if (c_sep(str[index], sep) == 0)
				break ;
			index++;
		}
	}
	else
	{
		while (str[index])
		{
			if (c_sep(str[index], sep) == 1)
				break ;
			index++;
		}
	}
	return (index);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (c_sep(str[i], charset) == 0)
		{
			cnt++;
			i = jump(str, charset, 1, i);
		}
		else
			i = jump(str, charset, 0, i);
	}
	return (cnt);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (c_sep(str[i], charset) == 0)
			cnt++;
		else
			break ;
		i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		index[2];
	char	**ans;
	int		cnt;

	index[0] = 0;
	cnt = count_words(str, charset);
	ans = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (ans == 0)
		return (0);
	while (*str)
	{
		if (c_sep(*str, charset) == 0)
		{
			index[1] = 0;
			cnt = word_count(str, charset);
			ans[index[0]] = (char *)malloc(sizeof(char) * (cnt + 1));
			while (c_sep(*str, charset) == 0 && *(str) != '\0')
				ans[index[0]][index[1]++] = *(str++);
			ans[index[0]++][index[1]] = '\0';
		}
		else
			str++;
	}
	ans[index[0]] = 0;
	return (ans);
}
