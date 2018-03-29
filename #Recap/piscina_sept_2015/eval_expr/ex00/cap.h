/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 09:11:52 by goarga            #+#    #+#             */
/*   Updated: 2015/09/20 21:59:23 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAP_H
# define CAP_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		grad1();
int		grad2();
int		ciorba();
int		size(char *str);
void	valid(char *str);
int		eval_expr(char *str);

#endif
