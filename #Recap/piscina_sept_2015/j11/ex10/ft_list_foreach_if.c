/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 21:25:09 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/17 21:32:46 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list *p;

	p = begin_list;
	while (p)
	{
		if ((*cmp)(p->data, data_ref) == 0)
			(*f)(p->data);
		p = p->next;
	}
}
