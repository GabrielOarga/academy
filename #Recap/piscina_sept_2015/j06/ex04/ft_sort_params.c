/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 20:53:14 by nmuresan          #+#    #+#             */
/*   Updated: 2015/09/10 21:40:30 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == '\0' && s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

void	bubble(char **s, int n)
{
	int		i;
	int		ok;
	char	*a;

	i = 1;
	ok = 0;
	while (ok == 0)
	{
		i = 1;
		ok = 1;
		while (i < n)
		{
			if (ft_strcmp(s[i], s[i + 1]) > 0)
			{
				a = s[i];
				s[i] = s[i + 1];
				s[i + 1] = a;
				ok = 0;
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	bubble(argv, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
