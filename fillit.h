/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:24:32 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/07 21:27:26 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_shape
{
	char	arr[4][4];
}				t_shape;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_points
{
	char	letter;
	t_point	arr[4];
}				t_points;

typedef struct	s_map
{
	char	**arr;
	int		y_len;
	int		x_len;
}				t_map;

void			errmsg(void);
int				last_char(char *fn);
int				get_size(char *file_name);
void			fill_array(char *fn, t_shape *mas, int size);
int				check_shape(t_shape *obj, int size);
t_map			*fillit(t_shape *pt, int size);
t_map			*map_creation(int num);
int				map_min_size(int n);
t_points		**trans_chars(t_shape *obj, int size);
int				placing(t_points *figure, t_map *map, int i, int j);
void			removing(t_points *figure, t_map *map, int i, int j);
t_map			*map_resizing(t_map *old_map);
void			show(t_map *result);
void			ft_putchar(char c);

#endif
