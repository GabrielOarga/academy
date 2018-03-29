/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 14:30:09 by goarga            #+#    #+#             */
/*   Updated: 2015/09/19 16:29:58 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

#include <stdlib.h>

typedef struct	s_btree
{
	struct s_btree 	*left;
	struct s_btree 	*right;
	void			*item;
}				t_btree;

#endif
