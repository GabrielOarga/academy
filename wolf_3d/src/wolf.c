/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 11:35:38 by goarga            #+#    #+#             */
/*   Updated: 2016/03/07 23:02:49 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			main(int argc, char **argv)
{
	t_wolf		*w;

	w = (t_wolf*)ft_memalloc(sizeof(t_wolf));
	init_param(w);
	usage_main(argc, argv[1]);
	map_control(w, argv[1]);
	init_mlx(w);
	wolf_expose(w);
	hook_controler(w);
	return (0);
}
