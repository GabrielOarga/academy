/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 17:25:43 by goarga            #+#    #+#             */
/*   Updated: 2015/09/17 21:28:52 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*ciorba;

	ciorba = *begin_list;
	if (ciorba)
	{
		while (ciorba->next != NULL)
			ciorba = ciorba->next;
		ciorba->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
