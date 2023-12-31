/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numberic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:27:27 by ghwang            #+#    #+#             */
/*   Updated: 2023/07/23 21:33:09 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (*(str + i) != '\0')
	{
		if (!(*(str + i) >= '0' && *(str + i) <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (r);
}
