/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abirthda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:46:11 by abirthda          #+#    #+#             */
/*   Updated: 2020/11/04 17:27:33 by abirthda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*start;

	if (!lst || !f)
		return (0);
	if (!(node = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&node, del);
		return (0);
	}
	start = node;
	lst = lst->next;
	while (lst)
	{
		if (!(node = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	return (start);
}
