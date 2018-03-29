#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_struct
{
	struct s_struct	*next;
	char			data;
}					t_lst;

#endif
