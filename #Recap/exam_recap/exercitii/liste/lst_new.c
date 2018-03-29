#include "list.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

t_lst	*lst_new(char chr, int size)
{
	t_lst	*lst;
	t_lst	*b_list;

	lst = (t_lst*)malloc(sizeof(t_lst));
	b_list = lst;
	while ((size - 1) > 0)
	{
		lst->next = (t_lst*)malloc(sizeof(t_lst));
		lst->data = (char)malloc(sizeof(char) * 1);
		lst->data = chr;
		lst = lst->next;
		size--;
	}
	lst->next = NULL;
	return (b_list);
}

int		lst_size(t_lst *b_list)
{
	int		i;

	i = 0;
	while(b_list != 0)
	{
		i++;
		b_list = b_list->next;
	}
	return (i);
}

void	lst_print(t_lst *b_list)
{
	while(b_list != 0)
	{
		ft_putchar(b_list->data);
		ft_putchar('\n');
		b_list = b_list->next;
	}
}

int		main(void)
{
	char	chr;
	int		size;

	size = 10;
	chr = 'a';
	printf("%d\n", lst_size(lst_new(chr, size)));
	lst_print(lst_new(chr, size));
	return (0);
}
