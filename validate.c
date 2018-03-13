/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:06:18 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/07 21:14:04 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_char(t_shape obj)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (obj.arr[i][j] != '#' && obj.arr[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_block(t_shape obj)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (obj.arr[i][j] == '#')
				n++;
			j++;
		}
		i++;
	}
	return (n == 4 ? 1 : 0);
}

static int	check_figure(t_shape obj, int y, int x)
{
	int count;

	count = 0;
	if (x < 3 && obj.arr[y][x + 1] == '#')
		count++;
	if (x > 0 && obj.arr[y][x - 1] == '#')
		count++;
	if (y < 3 && obj.arr[y + 1][x] == '#')
		count++;
	if (y > 0 && obj.arr[y - 1][x] == '#')
		count++;
	return (count);
}

static int	find_block(t_shape obj, int k)
{
	t_points	point;
	int			i;
	int			j;
	int			links;

	i = 0;
	links = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (obj.arr[i][j] == '#')
			{
				point.arr[k].x = j;
				point.arr[k].y = i;
				links += check_figure(obj, point.arr[k].y, point.arr[k].x);
				k++;
			}
			j++;
		}
		i++;
	}
	return ((links >= 6) ? 1 : 0);
}

int			check_shape(t_shape *obj, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (check_char(obj[i]) == 0 || check_block(obj[i]) == 0 ||
			find_block(obj[i], 0) == 0)
			return (0);
		i++;
	}
	return (1);
}
