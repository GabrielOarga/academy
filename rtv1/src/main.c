/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 09:57:57 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 13:16:12 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char **argv)
{
	t_rt	*rt;

	(void)argc;
	rt = (t_rt*)malloc(sizeof(t_rt));
	handle_usage(argc, argv[1]);
	read_main(rt, argv[1]);
	init_param(rt);
	init_mlx(rt);
	expose_main(rt);
	hook_main(rt);
	return (0);
}
