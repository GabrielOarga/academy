/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 21:35:53 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/17 21:43:22 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref,
		int (*cmp)())
{
	t_list *p;

	p = begin_list;
	while (p)
	{
		if (cmp(p->data, data_ref) == 0)
			return (p->data);
		p = p->next;
	}
	return (NULL);
}
