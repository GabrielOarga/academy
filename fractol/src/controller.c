/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 18:02:58 by goarga            #+#    #+#             */
/*   Updated: 2016/02/29 22:55:10 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_get_fractol(t_param *p)
{
	if (p->aux.fractol == 1)
		mandelbrot_main(p);
	if (p->aux.fractol == 2)
		julia_main(p);
	if (p->aux.fractol == 3)
		burningship_main(p);
}

int		fractol_controller(t_param *p)
{
	mlx_clear(p);
	mlx_initialize(p);
	mlx_get_fractol(p);
	mlx_draw(p);
	return (0);
}

void	usage_check(t_param *p, int argc, char *input)
{
	if (argc != 2)
	{
		ft_putstr("\nERROR: Incorrect number of arguments\n");
		ft_putstr("usage: ./fractol fractol_of_your_choice:\n");
		ft_putstr("\tmandelbrot\n\tjulia\n\tburningship\n\n");
		exit(1);
	}
	if (ft_strequ(input, "mandelbrot") == 1)
		p->aux.fractol = 1;
	else if (ft_strequ(input, "julia") == 1)
		p->aux.fractol = 2;
	else if (ft_strequ(input, "burningship") == 1)
		p->aux.fractol = 3;
	else
	{
		ft_putstr("\nERROR: Invalid argument\n");
		ft_putstr("usage: ./fractol fractol_of_your_choice:\n");
		ft_putstr("\tmandelbrot\n\tjulia\n\tburningship\n\n");
		exit(1);
	}
}
