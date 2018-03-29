/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:39:40 by goarga            #+#    #+#             */
/*   Updated: 2015/09/19 18:37:25 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

t_btree *btree_create_node(void *item)
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

int		main(void)
{
	t_btree *t;

	t = btree_create_node("nu inteleg nimic");
	printf("%s", t->item);
}
