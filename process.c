/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:50:10 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 20:59:37 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit_exit(int code)
{
	if (code == 2)
		ft_putstr_fd(USAGE, 2);
	else if (code == 3)
		ft_putstr_fd("error\n", 1);
	exit(code);
}

int		validate_input(char *str, size_t lnum)
{
	int i;

	i = -1;
	if (!((lnum + 1) % (TET_SIZE + 1) == 0))
	{
		if (ft_strlen(str) != L_SIZE)
			fillit_exit(3);
		while (++i < L_SIZE)
			if (str[i] != '.' && str[i] != '#')
				fillit_exit(3);
	}
	else if (ft_strcmp(str, "\0"))
		fillit_exit(3);
	return (1);
}

t_tris	*t_points(char *piece[])
{
	int hash_cnt;
	int *points[TET_SIZE];
	int row;
	int col;

	hash_cnt = 0;
	row = -1;
	while (++row < TET_SIZE)
	{
		col = -1;
		while (++col < L_SIZE)
		{
			if (piece[row][col] == '#')
			{
				if (hash_cnt < TET_SIZE)
				{
					points[hash_cnt] = ft_intnew(2);
					points[hash_cnt][0] = row;
					points[hash_cnt][1] = col;
				}
				hash_cnt++;
			}
		}
	}
	return (validate_piece(piece, points, hash_cnt));
}

t_tris	*validate_piece(char *piece[], int *t[], int hash_cnt)
{
	int		i;
	int		n;
	int		r;

	i = -1;
	r = 0;
	n = 0;
	if (hash_cnt != TET_SIZE)
		tstore(piece, t, -1);
	while (++i < TET_SIZE - 1)
	{
		while (i < TET_SIZE - ++r)
		{
			if ((t[i][0] + 1 == t[i + r][0]) && (t[i][1] == t[i + r][1]))
				n += 2;
			if ((t[i][0] - 1 == t[i + r][0]) && (t[i][1] == t[i + r][1]))
				n += 2;
			if ((t[i][1] + 1 == t[i + r][1]) && (t[i][0] == t[i + r][0]))
				n += 2;
			if ((t[i][1] - 1 == t[i + 1][1]) && (t[i][0] == t[i + r][0]))
				n += 2;
		}
		r = 0;
	}
	return ((n == 6 || n == 8) ? tstore(piece, t, 1) : tstore(piece, t, -1));
}

t_tris	*orc(int fd)
{
	size_t	lnum;
	char	*cache[TET_SIZE];
	char	*line;
	t_tris	*data;

	lnum = 0;
	data = NULL;
	while (get_next_line(fd, &line))
	{
		if (validate_input(line, lnum))
		{
			if (!(((lnum + 1) % (TET_SIZE + 1) == 0) && lnum > 0))
				cache[lnum % (TET_SIZE + 1)] = ft_strdup(line);
			free(line);
			data = (!((lnum + 2) % (TET_SIZE + 1))) ? t_points(cache) : data;
			lnum++;
		}
		else
			fillit_exit(3);
	}
	(!((lnum + 1) % (TET_SIZE + 1) == 0)) ? tris_del(data) : lnum;
	(!((lnum + 1) % (TET_SIZE + 1) == 0)) ? fillit_exit(3) : lnum;
	return (data);
}
