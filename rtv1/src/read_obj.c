/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:12:00 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 11:27:15 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_obj_count(t_rt *rt, char *argv)
{
	char	*line;
	int		fd;

	fd = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		rt->obj_count++;
	if (fd > 0)
		close(fd);
}

void		assign_poz(t_rt *rt, char *argv)
{
	char	**split;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = 0;
	fd = open(argv, O_RDONLY);
	rt->obj = (t_obj*)malloc(sizeof(t_obj) * rt->obj_count);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		assign_main(rt, split, i);
		i++;
	}
	close(fd);
}

void		read_main(t_rt *rt, char *argv)
{
	get_obj_count(rt, argv);
	assign_poz(rt, argv);
}
