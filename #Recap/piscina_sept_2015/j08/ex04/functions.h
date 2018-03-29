/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 17:57:28 by goarga            #+#    #+#             */
/*   Updated: 2015/09/15 17:57:32 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <stdlib.h>

char				**ft_split_whitespaces(char *str);
int					ft_strlen(char *str);
char				*ft_strdup(char *str);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);

#endif
