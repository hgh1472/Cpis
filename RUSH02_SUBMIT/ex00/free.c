/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:20:19 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/06 18:20:21 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_list.h"

void	free_allocated(t_dict *head, char **temp, char *buff)
{
	write(1, "\n", 1);
	while (head->next != 0)
	{
		if (!(head->str))
			free(head->str);
		head = head->next;
		if (!head->prev)
			free(head->prev);
	}
	if (!head->str)
		free(head->str);
	if (!head->prev)
		free(head);
	if (!temp)
		free(temp);
	if (!buff)
		free(buff);
}
