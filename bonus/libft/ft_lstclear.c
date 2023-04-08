/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:07:32 by hakaddou          #+#    #+#             */
/*   Updated: 2022/03/01 19:18:56 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!*lst || !del)
		return ;
	tmp = *lst;
	ptr = *lst;
	while (tmp != NULL)
	{
		tmp = ptr->next;
		del((ptr)->content);
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}
