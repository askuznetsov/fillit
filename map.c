/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:18:37 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/07 21:22:18 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->y_len)
	{
		free(map->arr[i]);
		i++;
	}
	free(map->arr);
	free(map);
}

int			map_min_size(int n)
{
	int	i;
	int	num;

	i = 1;
	num = n * 4;
	while ((i * i) < num)
		i++;
	return (i);
}

static char	**create_array(int size)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * size);
	while (i < size)
	{
		arr[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (arr);
}

t_map		*map_creation(int num)
{
	int		x;
	int		y;
	t_map	*map;

	x = num;
	y = x;
	map = (t_map *)malloc(sizeof(t_map));
	map->arr = create_array(x);
	map->x_len = x;
	map->y_len = y;
	return (map);
}

t_map		*map_resizing(t_map *old_map)
{
	int		x;
	int		y;
	t_map	*new_map;

	x = old_map->x_len + 1;
	y = old_map->y_len + 1;
	free_map(old_map);
	new_map = (t_map *)malloc(sizeof(t_map));
	new_map->arr = create_array(x);
	new_map->x_len = x;
	new_map->y_len = y;
	return (new_map);
}
