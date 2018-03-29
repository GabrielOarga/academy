/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 22:27:28 by goarga            #+#    #+#             */
/*   Updated: 2015/09/17 22:27:31 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct					s_list
{
	struct s_list				*next;
	void						*data;
}								t_list;

t_list							*ft_create_elem(void *data);

#endif
