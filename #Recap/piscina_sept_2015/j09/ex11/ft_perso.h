/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 08:33:14 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/11 09:22:40 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

typedef struct			s_perso
{
	char	*name;
	float	life;
	int		age;
	char	*profession;
}						t_perso;
#endif
