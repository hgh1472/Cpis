/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwang <ghwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:25:41 by ghwang            #+#    #+#             */
/*   Updated: 2023/08/09 20:26:22 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	free_with_error(t_map *s_map, char *buff)
{
	free(s_map);
	free(buff);
	write(2, "map error\n", 10);
}

void	free_st_buf(t_map *s_map, char *buff)
{
	free(s_map);
	free(buff);
}

void	free_array(char **array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(array[i++]);
	}
	free(array);
}

void	free_map_with_err(t_map *s_map)
{
	free(s_map);
	write(2, "map error\n", 10);
}

void	free_dp(int **dp, int index)
{
	int	i;

	i = 0;
	while (i < index)
		free(dp[i++]);
	free(dp);
}
