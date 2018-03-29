/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 10:51:29 by goarga            #+#    #+#             */
/*   Updated: 2015/09/20 22:13:00 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"

char	*g_string;

int		eval_expr(char *str)
{
	valid(str);
	return (grad1());
}

int		grad1(void)
{
	int rez;

	rez = grad2();
	while (*g_string == '+' || *g_string == '-')
	{
		if (*g_string == '-')
		{
			g_string++;
			rez -= grad2();
		}
		else
		{
			g_string++;
			rez += grad2();
		}
	}
	return (rez);
}

int		grad2(void)
{
	int rez;

	rez = ciorba();
	while (*g_string == '*' || *g_string == '/' || *g_string == '%')
	{
		if (*g_string == '*')
		{
			g_string++;
			rez *= ciorba();
		}
		else if (*g_string == '/')
		{
			g_string++;
			rez /= ciorba();
		}
		else
		{
			g_string++;
			rez %= ciorba();
		}
	}
	return (rez);
}

int		ciorba(void)
{
	int rez;

	rez = 0;
	if (*g_string == '(')
	{
		g_string++;
		rez = grad1();
	}
	else
	{
		while (*g_string >= '0' && *g_string <= '9')
		{
			rez *= 10 + (*g_string - '0');
			g_string++;
		}
	}
	return (rez);
}
