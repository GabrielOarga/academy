/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 12:50:50 by goarga            #+#    #+#             */
/*   Updated: 2016/01/15 23:29:37 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_n(int count)
{
	int		i;

	i = 1;
	while (i * i < count * 4)
		i++;
	return (i);
}

void	fillit(void)
{
	char		**mat;
	int			n;

	g_viz = create_matrix(13);
	n = get_n(count_shapes(g_shapes));
	mat = create_matrix(n + 2);
	init_matrix(mat, n + 2);
	while (1)
		back(mat, n++, 0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**shapes;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
	}
	if (!(shapes = (char**)malloc(sizeof(char*) * 27)))
		exit_program();
	fd = open(argv[1], O_RDONLY);
	if (argc == 2 && check_fd(fd) == 1)
	{
		g_shapes = get_shapes(fd, shapes);
		fillit();
	}
	else
		exit_program();
	close(fd);
	return (0);
}
