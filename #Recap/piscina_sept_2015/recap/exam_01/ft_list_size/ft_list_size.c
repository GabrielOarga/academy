/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 21:14:40 by goarga            #+#    #+#             */
/*   Updated: 2015/09/25 21:45:15 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int i;
	t_list	zama;

	i = 0;
	zama = *begin_list;
	while (zama->next)
	{
		zama = zama->next;
		i++;
	}
	return (i);
}

int		main(void)
{

}ZZ
