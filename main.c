/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:33:58 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/07 20:56:52 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			errmsg(void)
{
	write(1, "error\n", 6);
	exit(0);
}

static t_shape	*create_tet(char *file_name, int size)
{
	t_shape *arr;

	arr = (t_shape *)malloc(sizeof(t_shape) * size);
	fill_array(file_name, arr, size);
	if (check_shape(arr, size) == 0)
		errmsg();
	return (arr);
}

int				main(int argc, char **argv)
{
	t_shape	*arr;
	t_map	*result;
	int		size;

	if (argc != 2)
		errmsg();
	if (last_char(argv[1]) == 0)
		errmsg();
	if (!(size = get_size(argv[1])))
		errmsg();
	arr = create_tet(argv[1], size);
	result = fillit(arr, size);
	show(result);
	return (0);
}
