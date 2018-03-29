/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 19:27:48 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/19 20:17:00 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int maxs;
	int maxd;

	if (!root)
		return (-1);
	else
	{
		maxd = btree_level_count(root->right);
		maxs = btree_level_count(root->left);
		if (maxd > maxs)
			return (maxd + 1);
		else
			return (maxs + 1);
	}
}
