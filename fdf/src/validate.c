/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 19:11:00 by goarga            #+#    #+#             */
/*   Updated: 2016/02/22 19:08:44 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	validate_arguments(int argc)
{
	if (argc < 2)
	{
		ft_putstr("ERROR: TOO FEW ARGUMENTS\n");
		exit(1);
	}
	if (argc > 2)
	{
		ft_putstr("ERROR: TOO MANY ARGUMENTS\n");
		exit(1);
	}
}

void	validate_file(char *file)
{
	int			fd;
	int			byte;
	static char	buff[2];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("ERROR: FILE DOES NOT EXIST\n");
		exit(1);
	}
	byte = read(fd, buff, 1);
	if (byte < 1)
	{
		ft_putstr("ERROR: FILE IS EMPTY\n");
		exit(1);
	}
	close(fd);
}
