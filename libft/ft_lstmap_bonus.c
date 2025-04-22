/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:55:29 by agarcia           #+#    #+#             */
/*   Updated: 2025/04/22 20:42:19 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;
	void	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		aux = ft_lstnew(tmp);
		if (!aux)
		{
			ft_lstclear(&res, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&res, aux);
		lst = lst->next;
	}
	return (res);
}
