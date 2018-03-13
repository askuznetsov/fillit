/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:46:31 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/07 18:50:43 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	backtracking(t_points **figure, t_map *map, int i, int size)
{
	int x;
	int y;

	if (i == size)
		return (1);
	y = 0;
	while (y < map->y_len)
	{
		x = 0;
		while (x < map->x_len)
		{
			if (!placing(figure[i], map, y, x))
			{
				if (backtracking(figure, map, i + 1, size))
					return (1);
				else
					removing(figure[i], map, y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map		*fillit(t_shape *pt, int size)
{
	t_map		*map;
	t_points	**point;

	map = map_creation(map_min_size(size));
	point = trans_chars(pt, size);
	while (!backtracking(point, map, 0, size))
		map = map_resizing(map);
	return (map);
}
