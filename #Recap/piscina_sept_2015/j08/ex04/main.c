/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 17:57:19 by goarga            #+#    #+#             */
/*   Updated: 2015/09/15 20:04:30 by goarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "ft_stock_par.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stock_par		*dest;

	dest = ft_param_to_tab(argc, argv);
	printf("size param: %d\n", (dest + 1)->size_param);
	printf("str: %s\n", (dest + 1)->str);
	printf("copy: %s\n", (dest + 1)->copy);
}
