/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:28:48 by vrabaib           #+#    #+#             */
/*   Updated: 2019/04/09 22:44:57 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define L_SIZE 4
# define TET_SIZE L_SIZE
# define MAX_TET 26
# define INVALID_INDEX 9
# define FILLED 42
# define USAGE "usage: fillit input_file\n"

typedef struct		s_tris
{
	int				**cor;
	int				letter;
	struct s_tris	*next;
}					t_tris;

int					fillit_exit(int code);
void				reset(t_tris *t, int **grid, int i, int j);
int					validate_input(char *str, size_t lnum);
t_tris				*t_points(char *piece[]);
t_tris				*validate_piece(char *piece[], int *t[], int hash_cnt);
t_tris				*orc(int fd);
t_tris				*tstore(char *piece[], int *t[], int status);
void				arfr(void **arr, size_t rows, int dp);
void				tris_del(t_tris *tetriminos);
t_tris				*tris_new(int *t[], int ltr, size_t rows, size_t cols);
int					**square_grid(size_t n);
size_t				smallest_square(size_t t_num);
int					hit(int **t_cor, int **grid, size_t g_size);
void				fillit(t_tris *t, int **grid, int i, int j);
int					backtracking(t_tris *t, int **grid, size_t g_size);
int					tris_size(t_tris *tetriminos);
void				print_grid(int **grid, size_t g_size);
int					**tris_shift(int *t[], int i, int j);
int					**tris_normalize(int *t[]);

#endif
