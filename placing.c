/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:15:05 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/07 21:18:17 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_available(t_map *map, t_points *tet, int i, int j)
{
	if (map->arr[i][j] != '.')
		return (1);
	if (map->arr[(i + tet->arr[1].y)][(j + tet->arr[1].x)] != '.')
		return (1);
	if (map->arr[(i + tet->arr[2].y)][(j + tet->arr[2].x)] != '.')
		return (1);
	if (map->arr[(i + tet->arr[3].y)][(j + tet->arr[3].x)] != '.')
		return (1);
	return (0);
}

static int		is_match(t_map *map, t_points *tet, int i, int j)
{
	if (i + tet->arr[1].y < 0 || j + tet->arr[1].x < 0)
		return (1);
	if (i + tet->arr[2].y < 0 || j + tet->arr[2].x < 0)
		return (1);
	if (i + tet->arr[3].y < 0 || j + tet->arr[3].x < 0)
		return (1);
	if (i + tet->arr[1].y > (map->y_len - 1) ||
		j + tet->arr[1].x > (map->x_len - 1))
		return (1);
	if (i + tet->arr[2].y > (map->y_len - 1) ||
		j + tet->arr[2].x > (map->x_len - 1))
		return (1);
	if (i + tet->arr[3].y > (map->y_len - 1) ||
		j + tet->arr[3].x > (map->x_len - 1))
		return (1);
	return (0);
}

int				placing(t_points *fig, t_map *map, int i, int j)
{
	if ((is_match(map, fig, i, j)))
		return (1);
	if ((is_available(map, fig, i, j)))
		return (1);
	map->arr[i][j] = fig->letter;
	map->arr[(i + fig->arr[1].y)][(j + fig->arr[1].x)] = fig->letter;
	map->arr[(i + fig->arr[2].y)][(j + fig->arr[2].x)] = fig->letter;
	map->arr[(i + fig->arr[3].y)][(j + fig->arr[3].x)] = fig->letter;
	return (0);
}

void			removing(t_points *figure, t_map *map, int i, int j)
{
	map->arr[i][j] = '.';
	map->arr[(i + figure->arr[1].y)][(j + figure->arr[1].x)] = '.';
	map->arr[(i + figure->arr[2].y)][(j + figure->arr[2].x)] = '.';
	map->arr[(i + figure->arr[3].y)][(j + figure->arr[3].x)] = '.';
}
