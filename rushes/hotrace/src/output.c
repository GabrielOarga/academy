/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 20:17:10 by goarga            #+#    #+#             */
/*   Updated: 2016/04/24 22:43:06 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int			search_elem(t_hot *hot, char *key, char **ret_val)
{
	t_elem	*start;

	start = hot->elem;
	if (start == NULL)
		return (-1);
	else
	{
		while (start != NULL)
		{
			if (ft_strcmp(start->key, key) == 0)
			{
				*ret_val = ft_strdup(start->val);
				return (0);
			}
			else
				start = start->next;
		}
	}
	return (-1);
}

void		output_main(t_hot *hot)
{
	char	*key;
	char	*ret_val;
	int		index;

	(void)*hot;
	key = (char*)malloc(sizeof(char) * BUFFSIZE);
	while (get_next_line(0, &key) > 0)
	{
		if (ft_strcmp(key, "\0") == 0)
			break ;
		index = get_key_index(key);
		if (search_elem(&hot[index], key, &ret_val) < 0)
		{
			ft_putstr(key);
			ft_putstr(": ");
			ft_putstr("Not found.\n");
		}
		else
			ft_putendl(ret_val);
	}
}
