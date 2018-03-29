/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:41:18 by goarga            #+#    #+#             */
/*   Updated: 2016/01/17 21:55:40 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 4096

typedef struct		s_gnl
{
	struct s_gnl	*next;
	char			*data;
	char			*poz;
	int				retur;
	int				fd;
}					t_gnl;

int		get_next_line(int const fd, char **line);

#endif
