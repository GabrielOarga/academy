/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:41:39 by goarga            #+#    #+#             */
/*   Updated: 2016/01/17 21:51:48 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		i;
	char	*line = NULL;
	char	*line2 = NULL;

	i = 1251;
	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	/*while (i > 0)
	  {
	  get_next_line(fd1, &line);
	  printf("%s\n", line);
	  get_next_line(fd2, &line);
	  printf("%s\n", line);
	  i--;
	  }
	  */
	while (i > 0)
	{
		get_next_line(fd1, &line);
			printf("%s\n", line);		
		i--;
	}

	while (	get_next_line(fd2, &line2))
			printf("%s\n", line2);
	close(fd2);
	close(fd1);
	return (0);
}










while (list->next)
{
	while (get_next_line(fd, &line))
		ft_putstr(line);
}






