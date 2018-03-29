/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 19:57:17 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 13:05:23 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		print_usage(void)
{
	ft_putstr("\nusage: ./wolf3d map_of_your_choice\n");
	ft_putstr("\n\t_______________________________________\n");
	ft_putstr("\t|  Maps are located in the maps dir   |\n");
	ft_putstr("\t|_____________________________________|\n\n");
}

void		check_file(char *argv)
{
	if (ft_strequ(ft_strrchr(argv, '.'), ".map") == 0)
	{
		ft_putstr("\nERROR: File extension is invalid (.map)\n");
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

void		usage_main(int argc, char *argv)
{
	check_param(argc);
	check_map(argv);
	check_file(argv);
}
