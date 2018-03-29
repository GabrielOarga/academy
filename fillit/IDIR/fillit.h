/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:44:23 by goarga            #+#    #+#             */
/*   Updated: 2016/01/15 23:47:01 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_coord
{
	int		i;
	int		j;
}					t_coord;

typedef	struct		s_elem
{
	int i;
	int j;
	int	pp;
	int index;
	int hash;
}					t_elem;

char	**g_shapes;
int		g_cshape;
char	**g_viz;

void				process_tetriminos(char **this_element, char *tetriminos);
void				directions_back(char **this_element, char **matrix,
	char **aux, t_elem *anexe);
int					check_fd(int fd);
int					check_line(char *line);
int					check_newline(char *line);
void				exit_program();
char				*save_line(char *tetriminos, char *line);
char				**get_shapes(int fd, char **shapes);
void				init_elem(t_elem *elem);
char				**create_matrix(int n);
void				init_matrix(char **mat, int n);
void				print_matrix(char **mat, int n);
int					put_shape(char **mat, t_coord c, int n, char *shape);
int					clear_shape(char **mat, t_coord c, int n, char *shape);
void				back(char **mat, int n, int shapei);
void				print_matrix(char **mat, int n);
int					count_shapes(char **shapes);
int					count_spaces(char **mat, int n);

#endif
