/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 14:42:19 by goarga            #+#    #+#             */
/*   Updated: 2015/09/17 14:42:21 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list *p;

	p = NULL;
	p = (t_list*)malloc(sizeof(t_list));
	if (p)
	{
		p->data = data;
		p->next = NULL;
	}
	return (p);
}
