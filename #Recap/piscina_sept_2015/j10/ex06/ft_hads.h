/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 21:16:59 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/15 22:02:33 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HADS_H
# define FT_HADS_H
# include <unistd.h>

void	ft_putchar(char c);
int		ft_strlen(char *s);
void	ft_putnbr(int nb);
long	ft_add(int x, int y);
long	ft_minus(int x, int y);
long	ft_multiply(int x, int y);
long	ft_divide(int x, int y);
long	ft_modulo(int x, int y);
int		ft_atoi(char *s);

#endif
