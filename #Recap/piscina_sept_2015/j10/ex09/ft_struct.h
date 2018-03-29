/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforgaci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 19:07:27 by pforgaci          #+#    #+#             */
/*   Updated: 2015/09/16 19:23:07 by pforgaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H
# include <unistd.h>

typedef struct	s_opp
{
	char	*op;
	int		(*f)(int, int);
}				t_opp;

void			ft_putchar(char c);
int				ft_strlen(char *s);
int				ft_strcmp(char *s1, char *s2);
void			ft_putnbr(int nbr);
int				ft_atoi(char *s);
int				ft_add(int x, int y);
int				ft_sub(int x, int y);
int				ft_div(int x, int y);
int				ft_mod(int x, int y);
int				ft_mul(int x, int y);
int				ft_usage(int x, int y);
int				ft_op(char *s);

#endif
