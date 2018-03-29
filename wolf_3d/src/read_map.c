/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 22:32:31 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 22:22:09 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		get_mapsize(char *map, t_wolf *w)
{
	char	**split;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		w->map.row += 1;
	split = ft_strsplit(line, ' ');
	while (split[w->map.col] != NULL)
		w->map.col += 1;
	close(fd);
	if (w->p.posx > (w->map.row - 2))
	{
		ft_putstr("\nERROR: PLAYER POSITION OUT OF BOUNDS!\n\n");
		print_usage();
		exit(1);
	}
	if (w->p.posy > (w->map.row - 2))
	{
		ft_putstr("\nERROR: PLAYER POSITION OUT OF BOUNDS!\n\n");
		print_usage();
		exit(1);
	}
}

char		**split_line(int fd)
{
	char	*line;

	if (get_next_line(fd, &line) > 0)
	{
		return (ft_strsplit(line, ' '));
	}
	return (0);
}

void		get_mapheight(char *map, t_wolf *w)
{
	char	**split;
	int		fd;
	int		row;
	int		col;

	fd = open(map, O_RDONLY);
	row = 0;
	w->map.height = (int**)ft_memalloc(sizeof(int*) * w->map.row);
	while (row < w->map.row)
	{
		col = 0;
		split = split_line(fd);
		w->map.height[row] = (int*)ft_memalloc(sizeof(int) * w->map.col);
		while (col < w->map.col)
		{
			w->map.height[row][col] = ft_atoi(split[col]);
			col++;
		}
		row++;
	}
	close(fd);
}

void		map_control(t_wolf *w, char *map)
{
	w->map.row = 0;
	w->map.col = 0;
	get_mapsize(map, w);
	get_mapheight(map, w);
}
