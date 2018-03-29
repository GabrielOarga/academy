/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 21:24:09 by goarga            #+#    #+#             */
/*   Updated: 2015/09/17 21:24:13 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		size;

	size = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}
