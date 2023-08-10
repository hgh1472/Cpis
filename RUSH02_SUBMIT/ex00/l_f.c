/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_f.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:19:41 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 18:19:48 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_dict	*init(char *val, long long int nb);
char	*make_num_space_check(char *buff);
int		initial_key_check(int num);
int		format_check(char *buff, int flag);
char	*make_num_sign_check(char *buff, int *min_cnt, int *sign_cnt);
char	*exchange_char_to_num(char *buff, long long int *temp);
int		length(char *str);
char	*enter_check(char *buff);
char	*colon_check(char *buff);
int		valid_check(char **buff, long long int *num, long long int *cnt);

long long int	make_num(char *buff, long long int *cnt, int *flag)
{
	long long int	temp;
	int				min_cnt;
	int				sign_cnt;

	min_cnt = 0;
	sign_cnt = 0;
	temp = 0;
	buff = make_num_space_check(buff);
	buff = make_num_sign_check(buff, &min_cnt, &sign_cnt);
	buff = exchange_char_to_num(buff, &temp);
	if (sign_cnt > 2 || min_cnt == 1)
		return (-1);
	if (initial_key_check(temp))
	{
		*cnt += 1;
		*flag = 1;
		return (temp);
	}
	*flag = 0;
	return (temp);
}

int	insertion(t_dict *head, t_dict *target)
{
	t_dict	*p;

	p = head;
	while (p->num <= target->num)
	{
		if (p->num == target->num)
			return (0);
		p = p->next;
	}
	target->next = p;
	target->prev = p->prev;
	p->prev->next = target;
	p->prev = target;
	return (1);
}

char	*make_str(char *buff)
{
	char	*temp;
	int		i;

	i = 0;
	while (*buff == ' ')
		buff++;
	temp = (char *)malloc(sizeof(char) * (length(buff) + 1));
	while (*buff != '\n')
	{
		if (*buff == '\n')
			break ;
		else
			temp[i++] = *buff;
		buff++;
	}
	temp[i] = '\0';
	return (temp);
}

int	make_list(t_dict *head, char *buff)
{
	long long int	num_cnt[2];
	char			*str;

	num_cnt[0] = 0;
	num_cnt[1] = 0;
	while (*buff)
	{
		if (!(valid_check(&buff, &num_cnt[0], &num_cnt[1])))
			return (0);
		if (*buff == '\n')
		{
			buff++;
			continue ;
		}
		buff = colon_check(buff);
		str = make_str(buff);
		buff = enter_check(buff);
		if (insertion(head, init(str, num_cnt[0])) == 0)
			return (0);
		buff++;
	}
	if (num_cnt[1] < 32)
		return (0);
	return (1);
}
