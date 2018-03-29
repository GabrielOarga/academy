/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 11:21:44 by goarga            #+#    #+#             */
/*   Updated: 2016/03/08 22:24:02 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define W_WIDTH 1191
# define W_HEIGHT 670
# define POSX 5
# define POSY 2
# define DIRX 0
# define DIRY 1
# define PLANEX 0.66
# define PLANEY 0
# define ANGLE 44

typedef struct	s_map
{
	int			row;
	int			col;
	int			**height;
}				t_map;

typedef struct	s_keyhook
{
	int			forward;
	int			back;
	int			rot_left;
	int			rot_right;
	int			reset;
	int			exit;
	int			contrastup;
	int			contrastdown;
	int			blurtoggle;
}				t_keyhook;

typedef struct	s_draw
{
	float		contrast;
	int			blur;
	int			color;
	int			drawstart;
	int			drawend;
}				t_draw;

typedef struct	s_position
{
	int			mapx;
	int			mapy;
	int			wallhit;
	int			stepx;
	int			stepy;
	int			wallside;
	int			wallheight;
	double		posx;
	double		posy;
	double		rayposx;
	double		rayposy;
	double		initdistx;
	double		initdisty;
	double		disty;
	double		distx;
	double		deltax;
	double		deltay;
	double		walldist;
	double		camerax;
}				t_position;

typedef struct	s_vector
{
	double		ang;
	double		olddirx;
	double		olddiry;
	double		dirx;
	double		diry;
	double		raydirx;
	double		raydiry;
	double		oldplanex;
	double		oldplaney;
	double		planex;
	double		planey;
}				t_vector;

typedef struct	s_aux
{
	int			w;
	int			h;
	int			kpress;
	int			clear;
}				t_aux;

typedef struct	s_wolf
{
	void		*mlx_id;
	void		*win_id;
	void		*img_id;
	char		*addr;
	int			addr_index;
	t_map		map;
	t_position	p;
	t_vector	v;
	t_aux		a;
	t_draw		d;
	t_keyhook	k;
}				t_wolf;

void			get_rainbow(t_wolf *w, int col);
void			usage_main(int argc, char *argv);
void			map_control(t_wolf *w, char *map);
void			init_mlx(t_wolf *w);
void			init_param(t_wolf *w);
void			hook_controler(t_wolf *w);
void			wolf_expose(t_wolf *w);
void			wolf_main(t_wolf *w);
void			movehook(t_wolf *w);
void			assign_colors(t_wolf *w);
void			keyhook(t_wolf *w);
void			print_usage(void);
int				wolf_control(t_wolf *w);
int				kphook(int keyhook, t_wolf *w);
int				krhook(int keyhook, t_wolf *w);

#endif
