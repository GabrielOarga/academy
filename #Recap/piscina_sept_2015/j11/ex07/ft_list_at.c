/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 18:56:39 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/17 19:01:01 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list)
	{
		nbr--;
		if (nbr == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
