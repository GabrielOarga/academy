#include "get_next_line.h"

void	create_list(int fd, t_gnl **new)
{
	t_gnl	*gnl;

	gnl = *new;
	if (gnl == NULL)
	{
		gnl = (t_gnl*)malloc(sizeof(t_gnl));
		gnl->next = NULL;
		gnl->data = NULL;
		gnl->fd = fd;
	}
	else
	{
		while (gnl != NULL && gnl->fd != fd)
			gnl = gnl->next;
		if (gnl == NULL)
		{
			gnl = (t_gnl*)malloc(sizeof(t_gnl));
			gnl->next = NULL;
			gnl->data = NULL;
			gnl->fd = fd;
		}
	}
	*new = gnl;
}

void	loop(t_gnl **new)
{
	char	*aux;
	char	*buff;
	t_gnl	*gnl;

	gnl = *new;
	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		gnl->retur = -1;
		return ;
	}
	gnl->retur = read(gnl->fd, buff, BUFF_SIZE);
	if (gnl->retur > 0)
	{
		buff[gnl->retur] = '\0';
		aux = ft_strjoin(gnl->data, buff);
		free(gnl->data);
		gnl->data = aux;
	}
	free(buff);
	*new = gnl;
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl = NULL;

	if (fd < 0 || !(line) || BUFF_SIZE < 0)
		return (-1);
	create_list(fd, &gnl);
	if (!(gnl->data) && (gnl->data = (char*)malloc(sizeof(char))) == NULL)
		return (-1);
	gnl->poz = ft_strchr(gnl->data, '\n');
	while (gnl->poz == NULL)
	{
		loop(&gnl);
		if (gnl->retur == 0)
		{
			if (ft_strlen(gnl->data) == 0)
				return (0);
			gnl->data = ft_strjoin(gnl->data, "\n");
		}
		if (gnl->retur < 0)
			return (-1);
		else
			gnl->poz = ft_strchr(gnl->data, '\n');
	}
	*line = ft_strsub(gnl->data, 0, ft_strlen(gnl->data) - ft_strlen(gnl->poz));
	gnl->data = ft_strdup(gnl->poz + 1);
	return (1);
}
