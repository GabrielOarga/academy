/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:56:46 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 23:24:01 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define W_HEIGHT 1000
# define W_WIDTH 1000
# define W_HEIGHT2 250
# define W_WIDTH2 500
# define MAX_STEPS 256

typedef struct	s_color
{
	float		index;
	float		b;
	float		g;
	float		r;
}				t_color;

typedef	struct	s_aux
{
	double		mouse_move_x;
	double		mouse_move_y;
	double		julia_x;
	double		julia_y;
	double		mouse_x;
	double		mouse_y;
	double		zoom;
	int			vomit;
	int			color_switch;
	int			toggle;
	int			stop_julia;
	int			zoom_index;
	int			ok;
	int			addr_index;
	int			max_iter;
	int			fractol;
}				t_aux;

typedef struct	s_param
{
	void		*mlx_id2;
	void		*window_id2;
	void		*mlx_id;
	void		*window_id;
	void		*image_id;
	char		*addr;
	int			ok;
	t_aux		aux;
	t_color		col;
}				t_param;

void			param_init(t_param *p);
void			mlx_clear(t_param *p);
void			mlx_initialize(t_param *p);
void			mlx_draw(t_param *p);
void			mlx_get_fractol(t_param *p);
void			usage_check(t_param *p, int argc, char *input);
int				fractol_controller(t_param *p);
void			mandelbrot_main(t_param *p);
void			mandelbrot_get_xy(t_param *p, double row, double col);
void			mandelbrot_calc_iter(t_param *p, double x, double y);
void			mandelbrot_assign_color(t_param *p, int iter);
void			julia_main(t_param *p);
void			julia_get_xy(t_param *p, double row, double col);
void			julia_calc_iter(t_param *p, double x, double y);
void			julia_assign_color(t_param *p, int iter);
void			burningship_main(t_param *p);
void			burningship_get_xy(t_param *p, double row, double col);
void			burningship_calc_iter(t_param *p, double x, double y);
void			burningship_assign_color(t_param *p, int iter);
void			reset(int keyhook, t_param *p);
void			switch_color(int keyhook, t_param *p);
int				keyhook_main(int keyhook, t_param *p);
int				mouse_hook(int button, int x, int y, t_param *p);
int				loop_hook(int x, int y, t_param *p);
void			color_set_black(t_param *p);
void			color_set_rainbow(t_param *p, int iter);
void			fast_rainbow(t_param *p, int iter);
void			slow_rainbow(t_param *p, int iter);
void			make_vomit(int keyhook, t_param *p);

#endif
