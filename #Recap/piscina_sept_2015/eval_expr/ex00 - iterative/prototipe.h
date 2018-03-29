/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototipe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 08:59:48 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/20 20:40:49 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTIPE_H
# define PROTOTIPE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *dest, char *source);
void	ft_putchar(char c);
void	ft_putchar(char c);
void	ft_putnbr(long n);
int		ft_strchr(char *s, char c);
void	eliminare_spatii(char *s);
int		numar_numere(char *s);
int		is_pos(char *s, int i);
long	creare_numar_din_sir(char *s, int i);
long	operation(int a, int b, char c);
long	*vector_number(char *s);
void	vector_operators(char *s);
int		incrementation(char c, int k);
long	*vector_incrementation(char *s);
void	elimination(long *v, int poz, int n);

#endif
