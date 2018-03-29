/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:46:39 by goarga            #+#    #+#             */
/*   Updated: 2016/04/24 22:36:33 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

# define BUFFSIZE 1000

typedef struct	s_elem
{
	char			*key;
	char			*val;
	struct s_elem	*next;
}				t_elem;

typedef struct	s_hot
{
	t_elem	*elem;
}				t_hot;

size_t			ft_strlen(const char *s);
void			input_main(t_hot *hot);
void			output_main(t_hot *hot);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
char			*ft_strdup(const char *s1);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				get_key_index(char *key);

#endif
