/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:09:16 by sehyupar          #+#    #+#             */
/*   Updated: 2023/08/09 20:39:45 by ghwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_square{
	int	size;
	int	x;
	int	y;
}	t_square;

typedef struct s_map{
	int		col;
	int		row;
	char	empty;
	char	obs;
	char	fill;
}	t_map;

void		free_dp(int **dp, int index);
int			dp(char **map, t_map *M, t_square *s);
void		fill_square(char **map, t_square *S, t_map *M);
void		find_square(char **map, t_map *M);
int			identical_check(char *index);
int			print_check(char *index);
int			fir_format_check(char *buff, t_map *s_map);
int			invalid(char *buff, t_map *s_map);
char		**change_buff(char *buff, int line, int col);
int			line_check(char *buff, t_map *m);
void		create_tmp(void);
void		free_dp(int **dp, int index);
void		free_with_error(t_map *s_map, char *buff);
void		free_st_buf(t_map *s_map, char *buff);
void		free_array(char **array, int index);
void		free_map_with_err(t_map *s_map);
int			size_check(char *temp);
char		*buff_in(char *temp, int index);
void		process(char *argv);

#endif
