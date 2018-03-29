/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:24:23 by goarga            #+#    #+#             */
/*   Updated: 2016/05/27 13:08:37 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define W_WIDTH 1000
# define W_HEIGHT 1000

typedef struct	s_orth
{
	double		a;
	double		b;
	double		c;
	double		discr;
}				t_orth;

typedef struct	s_vect3
{
	double		x;
	double		y;
	double		z;
}				t_vect3;

typedef struct	s_vect2
{
	double		x;
	double		y;
}				t_vect2;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef struct	s_cone
{
	t_vect3		co;
	t_vect3		dir;
	double		radius;
	double		angle;
}				t_cone;

typedef struct	s_sphere
{
	t_vect3		co;
	double		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_vect3		norm;
	t_vect3		co;
}				t_plane;

typedef struct	s_cilinder
{
	t_vect3		co;
	t_vect3		dir;
	double		radius;
}				t_cilinder;

typedef struct	s_obj
{
	t_sphere	sph;
	t_plane		pln;
	t_cilinder	cil;
	t_cone		cone;
	t_color		col;
	t_orth		orth;
	double		d0;
	double		d1;
	double		ld0;
	double		ld1;
	double		lumdist;
	double		ang;
	char		type;
	int			hit;
	int			lhit;
}				t_obj;

typedef struct	s_vect
{
	t_vect3		dir;
	t_vect3		ray;
	t_vect3		rayorig;
	t_vect3		isect;
	t_vect3		lumorig;
	t_vect3		lum;
	t_vect3		norm;
	t_vect3		orig;
	t_vect2		vers;
}				t_vect;

typedef struct	s_aux
{
	double		min_dist;
	int			clear_image_init;
	int			bpp;
	int			lsize;
	int			endian;
}				t_aux;

typedef struct	s_rt
{
	void		*mlx_id;
	void		*win_id;
	void		*img_id;
	char		*data;
	int			data_index;
	int			obj_count;
	int			obj_index;
	int			obj_index2;
	t_vect		v;
	t_obj		*obj;
	t_aux		a;
}				t_rt;

t_vect3			vnorm_v3(t_vect3 v);
t_vect3			ivsmult_v3(t_vect3 v, double scal);
t_vect3			vsmult_v3(double scal, t_vect3 v);
t_vect3			vectadd_v3(t_vect3 v1, t_vect3 v2);
t_vect3			vectsub_v3(t_vect3 v1, t_vect3 v2);
t_vect3			crossprod_v3(t_vect3 v1, t_vect3 v2);
t_vect3			vrotate_v3(t_vect3 v, double angle);
double			dotprod_v3(t_vect3 v1, t_vect3 v2);
double			vlen_v3(t_vect3 v);
double			ft_absd(double nr);
double			to_deg(double rad);
double			to_rad(double deg);
void			handle_usage(int argc, char *argv);
void			init_mlx(t_rt *rt);
void			init_param(t_rt *rt);
void			expose_main(t_rt *rt);
void			hook_main(t_rt *rt);
void			calc_dotprod(t_rt *rt);
void			rt_main(t_rt *rt);
void			calc_orth(double a, double b, double c, t_rt *rt);
void			draw_scene(t_rt *rt);
void			read_main(t_rt *rt, char *argv);
void			assign_main(t_rt *rt, char **split, int i);
void			calc_shading(t_rt *rt);
void			calc_sphere_intersect(int sel, t_vect3 ray,
		t_obj *obj, t_rt *rt);
void			calc_plane_intersect(int sel, t_vect3 ray,
		t_obj *obj, t_rt *rt);
void			calc_cilin_intersect(int sel, t_vect3 ray,
		t_obj *obj, t_rt *rt);
void			calc_cone_intersect(int sel, t_vect3 ray,
		t_obj *obj, t_rt *rt);
int				rt_controler(t_rt *rt);

#endif
