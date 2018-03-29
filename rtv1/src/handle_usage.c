/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:18:01 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 13:21:57 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		print_usage(void)
{
	ft_putstr("\nusage: ./rtv1 scene of your choice\n");
	ft_putstr("\n\t _____________________________________\n");
	ft_putstr("\t|                                     |\n");
	ft_putstr("\t|    Scenes are located in obj dir    |\n");
	ft_putstr("\t|_____________________________________|\n\n");
}

void		check_file(char *argv)
{
	if (ft_strequ(ft_strrchr(argv, '.'), ".scene") == 0)
	{
		ft_putstr("\nERROR: File extension is invalid (.scene)\n");
		print_usage();
		exit(1);
	}
}

void		check_map(char *map)
{
	static char	buff[2];
	int			fd;
	int			byte;

	fd = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("\nERROR: File does not exist or is invalid\n");
		print_usage();
		exit(1);
	}
	byte = read(fd, buff, 1);
	if (byte < 1)
	{
		ft_putstr("\nERROR: File is empty or is invalid\n");
		print_usage();
		exit(1);
	}
	if (fd > 0)
		close(fd);
}

void		check_param(int argc)
{
	if (argc != 2)
	{
		ft_putstr("\nERROR: Invalid number of parameters\n");
		print_usage();
		exit(1);
	}
}

void		handle_usage(int argc, char *argv)
{
	check_param(argc);
	check_map(argv);
	check_file(argv);
}
