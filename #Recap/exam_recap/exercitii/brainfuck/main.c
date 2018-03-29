/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 19:47:52 by goarga            #+#    #+#             */
/*   Updated: 2016/01/13 19:47:55 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		g_loop[4500];
int		g_vector[2050];
int		g_i;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	verif(char c)
{
	if (c == '>')
		g_i++;
	if (c == '<')
		g_i--;
	if (c == '+')
		g_vector[g_i]++;
	if (c == '-')
		g_vector[g_i]--;
	if (c == '.')
		ft_putchar(g_vector[g_i]);
}

void	computation(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		verif(str[i]);
		if (str[i] == '[' && g_vector[g_i] == 0)
			i = g_loop[i];
		else if (str[i] == ']' && g_vector[g_i] != 0)
			i = g_loop[i];
		else
			i++;
	}
}

void	fuck(char *str)
{
	int		i;
	int		stack[2000];
	int		vf;

	i = 0;
	vf = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '[')
		{
			stack[vf] = i;
			vf++;
		}
		if (str[i] == ']')
		{
			vf--;
			g_loop[i] = stack[vf];
			g_loop[stack[vf]] = i;
		}
		i++;
	}
	computation(str);
}

int		main(int argc, char **argv)
{
	g_i = 0;
	if (argc > 1)
		fuck(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
