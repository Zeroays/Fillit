/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:46:26 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 21:34:31 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	size_t	msq;
	t_tris	*tetris;
	int		**grid;

	if (argc == 2)
	{
		(!(fd = open(argv[1], O_RDONLY)) || fd < 0) ? fillit_exit(2) : fd;
		tetris = orc(fd);
		msq = smallest_square(tris_size(tetris));
		grid = square_grid(msq);
		while (!(backtracking(tetris, grid, msq)))
		{
			arfr((void **)grid, msq, 1);
			msq++;
			grid = square_grid(msq);
		}
		print_grid(grid, msq);
		tris_del(tetris);
		arfr((void **)grid, msq, 1);
		close(fd);
	}
	else
		fillit_exit(2);
	return (0);
}
