#include "libft.h"
#include <stdio.h>

int     main(void)
{
        t_list  *list;
        t_list  *last;


        list = NULL;
        ft_lstadd_back(&list, ft_lstnew("node 1\0"));
        ft_lstadd_back(&list, ft_lstnew("node 2\0"));
        ft_lstadd_back(&list, ft_lstnew("node 3\0"));
        last = ft_lstlast(list);
        if (last && list)
                printf("last : %s\n", (char *)last->content);
        return (0);
}

