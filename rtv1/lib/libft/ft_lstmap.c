/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:28:27 by goarga            #+#    #+#             */
/*   Updated: 2015/12/14 18:28:38 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*start;
	t_list		*nlst;

	if (lst == NULL)
		return (NULL);
	nlst = f(lst);
	if (nlst == NULL)
		return (NULL);
	start = nlst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		nlst->next = f(lst);
		if (nlst->next == NULL)
			return (NULL);
		nlst = nlst->next;
	}
	return (start);
}
