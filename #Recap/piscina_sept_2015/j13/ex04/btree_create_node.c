/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:39:40 by goarga            #+#    #+#             */
/*   Updated: 2015/09/19 19:09:03 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*p;

	p = NULL;
	p = (t_btree*)malloc(sizeof(t_btree));
	if (p)
	{
		p->item = item;
		p->left = 0;
		p->right = 0;
	}
	return (p);
}
