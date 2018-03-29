/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:30:41 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 19:10:18 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_matrix(char *file, t_env *env)
{
	char	**split;
	int		row;
	int		col;
	int		fd;

	validate_file(file);
	get_row(file, &env->mat.row, &env->mat.col);
	fd = open(file, O_RDONLY);
	row = 0;
	env->mat.matrix = (int**)malloc(sizeof(int*) * env->mat.row);
	while (row < env->mat.row)
	{
		col = 0;
		split = split_line(fd);
		env->mat.matrix[row] = (int*)malloc(sizeof(int) * env->mat.col);
		while (col < env->mat.col)
		{
			env->mat.matrix[row][col] = ft_atoi(split[col]);
			col++;
		}
		row++;
	}
	close(fd);
}

char	**split_line(int fd)
{
	char	**split;
	char	*line;

	if (get_next_line(fd, &line) > 0)
		split = ft_strsplit(line, ' ');
	else
		exit(1);
	return (split);
}

int		get_col(char *line)
{
	int		col;
	char	**col_line;

	col_line = ft_strsplit(line, ' ');
	col = 0;
	while (col_line[col] != NULL)
		col++;
	return (col);
}

void	get_row(char *file, int *row, int *col)
{
	char	*line;
	int		fd;
	int		ok;

	ok = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ok == 0)
			*col = get_col(line);
		if (ok == 1 && *col != get_col(line))
		{
			ft_putstr("ERROR: FILE CONTENT INVALID: MAP SIZE INVALID\n");
			exit(1);
		}
		ok = 1;
		(*row)++;
	}
	close(fd);
}
