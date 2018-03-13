/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 12:04:17 by abibyk            #+#    #+#             */
/*   Updated: 2018/03/13 12:04:19 by abibyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		show(t_map *result)
{
	int i;
	int j;

	i = 0;
	while (i < result->y_len)
	{
		j = 0;
		while (j < result->x_len)
		{
			ft_putchar(result->arr[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			get_size(char *file_name)
{
	int		file;
	int		size;
	int		row;
	int		ret;
	char	ch;

	size = 0;
	row = 0;
	file = open(file_name, O_RDONLY);
	while ((ret = read(file, &ch, 1)) == 1)
	{
		if (ch == '\n')
		{
			row++;
			if (row % 4 == 0)
			{
				size++;
				ret = read(file, &ch, 1);
			}
		}
	}
	if (row % 4)
		errmsg();
	close(file);
	return (size);
}

int			last_char(char *fn)
{
	int		file;
	size_t	ret;
	char	ch;
	char	old_ch[2];

	file = open(fn, O_RDONLY);
	old_ch[0] = '\n';
	old_ch[1] = '\n';
	while ((ret = read(file, &ch, 1)) == 1)
	{
		old_ch[0] = old_ch[1];
		old_ch[1] = ch;
	}
	close(file);
	return (ch == '\n' && old_ch[0] != '\n' ? 1 : 0);
}
