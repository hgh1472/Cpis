/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_ut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:21:25 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 18:21:28 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_dict	*init(char *val, long long int nb)
{
	t_dict	*new;

	new = (t_dict *) malloc (sizeof(t_dict));
	new->num = nb;
	new->str = val;
	new->next = 0;
	new->prev = 0;
	return (new);
}

char	*make_num_space_check(char *buff)
{
	while (*buff <= 32)
		buff++;
	return (buff);
}

char	*make_num_sign_check(char *buff, int *min_cnt, int *sign_cnt)
{
	while (*buff == '+' || *buff == '-')
	{
		if (*buff == '-')
			(*min_cnt)++;
		(*sign_cnt)++;
		buff++;
	}
	return (buff);
}

char	*exchange_char_to_num(char *buff, long long int *temp)
{
	while (*buff != ':')
	{
		if (*buff >= '0' && *buff <= '9')
			*temp = ((*temp) * 10) + (*buff - '0');
		buff++;
	}
	buff++;
	return (buff);
}

int	length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
