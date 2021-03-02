/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:23:08 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/12 00:11:40 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*first;

	if (!lst || !f)
		return (0);
	if (!(result = ft_lstnew(f(lst->content))))
		return (0);
	first = result;
	while (lst)
	{
		if (lst->next)
		{
			if (!(result->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&first, del);
				return (0);
			}
			result = result->next;
		}
		lst = lst->next;
	}
	result->next = 0;
	return (first);
}
