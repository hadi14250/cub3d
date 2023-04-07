/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:16:49 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:21:45 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*res;

	if (!lst)
		return (NULL);
	res = NULL;
	while (lst != NULL)
	{
		ptr = ft_lstnew(f(lst->content));
		if (!ptr)
		{
			del(ptr->content);
			free(ptr);
			return (NULL);
		}
		ft_lstadd_back(&res, ptr);
		lst = lst->next;
	}
	return (res);
}
