/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:43:20 by goarga            #+#    #+#             */
/*   Updated: 2016/03/05 20:11:31 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define W_WIDTH  1920
# define W_HEIGHT  1080

typedef struct	s_struct
{
	int			**matrix;
	int			col;
	int			row;
}				t_matrix;

typedef struct	s_poz
{
	float		co_x;
	float		co_y;
}				t_poz;

typedef struct	s_trig
{
	float		scale;
	float		offset_z;
	float		static_offset_x;
	float		static_offset_y;
	float		dynamic_offset_x;
	float		dynamic_offset_y;
	float		zoom_scale;
	float		height_scale;
	int			color;
	int			prec;
	int			seg;
}				t_trig;

typedef struct	s_env
{
	void		*init_ptr;
	void		*window_id;
	t_poz		**poz;
	t_matrix	mat;
	t_trig		trig;
}				t_env;

void			validate_arguments(int argc);
void			validate_file(char *file);
void			read_matrix(char *file, t_env *env);
void			get_row(char *file, int *row, int *col);
void			get_pixel_poz(t_env *env);
void			draw_line(t_env *env, t_poz x, t_poz y);
void			get_scale(t_env *env);
void			get_offset_z(t_env *env);
void			draw_stuff(t_env *env);
void			reset(t_env *env);
char			**split_line(int fd);
float			calc_offset_y(int row, int col);
float			calc_offset_z(int z);
int				rainbow(t_env *env);
int				keyhook(int keyhook, t_env *env);
int				expose(t_env *env);
void			draw_legend(t_env *env);
void			reset(t_env *env);
void			reset_exit(int keyhook, t_env *env);
void			seg(t_env *env);
void			removethis(int keyhook, t_env *env);
void			colors(int keyhook, t_env *env);
char			*get_color(char *rainbow, int color);
char			*get_color_2(char *rainbow, int color);

#endif
