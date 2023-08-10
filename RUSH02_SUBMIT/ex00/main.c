/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:22:30 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 18:28:52 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_list.h"

void			free_allocated(t_dict *head, char **temp, char *buff);
long long int	ft_atoi(char *str);
t_dict			*init(char *val, long long int nb);
int				make_list(t_dict *head, char *buff);
char			*make_str(char *buf);
void			change(long long int a, t_dict *head);
char			**input_check(int argc, char **argv);
int				dict_size_check(char **temp);
int				arg_check(int argc, char **temp);
void			h_and_t(t_dict *s_head, t_dict *s_tail);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*buff_in(char **temp, int index)
{
	char	*buff;
	int		fd;

	fd = open(temp[0], O_RDONLY);
	buff = (char *)malloc(sizeof(char) * (index + 1));
	if (0 < fd)
	{
		read(fd, buff, index + 1);
		close(fd);
	}
	else
		buff[0] = '\0';
	return (buff);
}

int	main(int argc, char **argv)
{
	char	*buff;
	char	**temp;
	t_dict	*s_head;
	t_dict	*s_tail;

	temp = input_check(argc, argv);
	if (arg_check(argc, temp) == 0)
		return (0);
	argc = dict_size_check(temp);
	buff = buff_in(temp, argc);
	if (buff[0] == '\0')
		return (0);
	s_head = init("", -1);
	s_tail = init("", 9223372036854775589);
	h_and_t(s_head, s_tail);
	if (make_list(s_head, buff) == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (ft_atoi(temp[1]) == 0)
		write(1, s_head->next->str, ft_strlen(s_head->next->str));
	change(ft_atoi(temp[1]), s_tail);
	free_allocated(s_head, temp, buff);
	return (0);
}

void	change(long long int a, t_dict *tail)
{
	t_dict	*s_p;

	s_p = tail;
	while (s_p->num > 0)
	{
		if (a / s_p->num > 0)
		{
			if (a >= (long long)100)
				change((long long)(a / s_p->num), s_p);
			write(1, s_p->str, ft_strlen(s_p->str));
			write(1, " ", 1);
			change((long long)(a % s_p->num), s_p);
			return ;
		}
		s_p = s_p->prev;
	}
}
