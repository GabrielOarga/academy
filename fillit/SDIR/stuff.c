/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 20:26:41 by goarga            #+#    #+#             */
/*   Updated: 2016/01/15 23:54:23 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_shapes(char **shapes)
{
	int		count;

	count = 0;
	while (shapes[count])
		count++;
	return (count);
}

char	**create_matrix(int n)
{
	int		index;
	char	**result;

	result = (char**)malloc(sizeof(char*) * n);
	index = 0;
	while (index < n)
		result[index++] = (char*)malloc(n);
	return (result);
}

void	init_matrix(char **mat, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			mat[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	print_matrix(char **mat, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(mat[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		check_fd(int fd)
{
	if (fd == -1)
		exit_program();
	return (1);
}
