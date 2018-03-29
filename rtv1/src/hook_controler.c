/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 10:51:10 by goarga            #+#    #+#             */
/*   Updated: 2016/05/28 11:58:41 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			keyhook_main(int keyhook, t_rt *rt)
{
	if (keyhook == 53)
		exit(0);
	if (keyhook == 125)
		rt->v.lumorig.x += 5;
	if (keyhook == 126)
		rt->v.lumorig.x -= 5;
	if (keyhook == 124)
		rt->v.lumorig.y += 5;
	if (keyhook == 123)
		rt->v.lumorig.y -= 5;
	if (keyhook == 47)
		rt->v.lumorig.z += 10;
	if (keyhook == 43)
		rt->v.lumorig.z -= 10;
	if (keyhook == 15)
	{
		rt->v.lumorig.x = 0;
		rt->v.lumorig.y = 0;
		rt->v.lumorig.z = 0;
	}
	rt_controler(rt);
	return (0);
}

void		hook_main(t_rt *rt)
{
	mlx_key_hook(rt->win_id, keyhook_main, rt);
	mlx_loop(rt->mlx_id);
}
