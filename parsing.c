/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:57:31 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/07 21:05:52 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_shape	fill_tet(int *file)
{
	int		i;
	int		j;
	char	ch;
	t_shape	tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			read(*file, &ch, 1);
			tmp.arr[i][j] = ch;
			j++;
		}
		read(*file, &ch, 1);
		i++;
	}
	return (tmp);
}

void			fill_array(char *file_name, t_shape *mas, int size)
{
	int		file;
	int		n;
	char	ch;

	file = open(file_name, O_RDONLY);
	n = 0;
	while (n < size)
	{
		mas[n] = fill_tet(&file);
		read(file, &ch, 1);
		n++;
	}
	close(file);
}

static t_points	*transform(t_points *pt)
{
	int i;

	i = 3;
	while (i >= 0)
	{
		pt->arr[i].y -= pt->arr[0].y;
		pt->arr[i].x -= pt->arr[0].x;
		i--;
	}
	return (pt);
}

static t_points	*trans_char(t_shape obj)
{
	t_points	*point;
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	point = (t_points *)malloc(sizeof(t_points));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (obj.arr[i][j] == '#')
			{
				point->arr[k].x = j;
				point->arr[k].y = i;
				k++;
			}
			j++;
		}
		i++;
	}
	return (transform(point));
}

t_points		**trans_chars(t_shape *obj, int size)
{
	int			i;
	char		c;
	t_points	**figure;

	c = 65;
	i = 0;
	figure = (t_points **)malloc(sizeof(t_points *) * size);
	while (i < size)
	{
		figure[i] = trans_char(obj[i]);
		figure[i]->letter = c + i;
		i++;
	}
	return (figure);
}
