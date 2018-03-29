/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:20:31 by goarga            #+#    #+#             */
/*   Updated: 2016/04/24 22:43:29 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void		create_elem(t_hot *hot, char *key, char *val)
{
	hot->elem = (t_elem*)malloc(sizeof(t_elem));
	hot->elem->key = ft_strdup(key);
	hot->elem->val = ft_strdup(val);
	hot->elem->next = NULL;
}

void		insert_elem(t_hot *hot, char *key, char *val)
{
	t_elem	*new;
	t_elem	*aux;

	aux = hot->elem;
	new = (t_elem*)malloc(sizeof(t_elem));
	new->key = ft_strdup(key);
	new->val = ft_strdup(val);
	new->next = aux;
	hot->elem = new;
}

int			get_key_index(char *key)
{
	int		res;

	res = 0;
	while (*key)
	{
		res = res + (int)*key;
		key++;
	}
	return (res);
}

void		input_main(t_hot *hot)
{
	char	*key;
	char	*val;
	int		index;

	key = (char*)malloc(sizeof(char) * BUFFSIZE);
	val = (char*)malloc(sizeof(char) * BUFFSIZE);
	while (get_next_line(0, &key) > 0)
	{
		if (ft_strcmp(key, "\0") == 0)
			break ;
		if (get_next_line(0, &val) <= 0)
			exit(1);
		index = get_key_index(key);
		if (hot[index].elem == NULL)
			create_elem(&hot[index], key, val);
		else
			insert_elem(&hot[index], key, val);
	}
}
