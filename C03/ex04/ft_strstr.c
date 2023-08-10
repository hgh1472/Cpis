/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:09:16 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/25 14:44:11 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	len(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		i2;
	int		leng;
	int		cnt;
	char	*ptr;

	ptr = 0;
	if (*(to_find) == '\0')
		return (str);
	i = 0;
	i2 = 0;
	cnt = 0;
	leng = len(to_find);
	while (*(str + i) != '\0')
	{
		if (*(str + i) == *(to_find + cnt))
			cnt++;
		else
			cnt = 0;
		if (leng == cnt)
			return (str + i - cnt + 1);
		i++;
	}
	return (ptr);
}
