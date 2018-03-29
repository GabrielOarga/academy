/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:41:29 by goarga            #+#    #+#             */
/*   Updated: 2016/01/17 21:22:49 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_loop(int const fd, char **data)
{
	char		*aux;
	char		*buff;
	int			retur;

	if (!(buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	retur = read(fd, buff, BUFF_SIZE);
	if (retur > 0)
	{
		buff[retur] = '\0';
		aux = ft_strjoin(*data, buff);
		free(*data);
		*data = aux;
	}
	free(buff);
	return (retur);
}

int		get_next_line(int const fd, char **line)
{
	static char	*data = NULL;
	char		*poz;
	int			retur;

	if ((!data && (data = (char*)malloc(sizeof(char))) == NULL) ||
			!(line) || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	poz = ft_strchr(data, '\n');
	while (poz == NULL)
	{
		retur = get_loop(fd, &data);
		if (retur == 0)
		{
			if (ft_strlen(data) == 0)
				return (0);
			data = ft_strjoin(data, "\n");
		}
		if (retur < 0)
			return (-1);
		else
			poz = ft_strchr(data, '\n');
	}
	*line = ft_strsub(data, 0, ft_strlen(data) - ft_strlen(poz));
	data = ft_strdup(poz + 1);
	return (1);
}
