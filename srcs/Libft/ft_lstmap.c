/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 17:11:01 by scleerdi      #+#    #+#                 */
/*   Updated: 2021/11/17 14:04:49 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*new_list_item(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	void	*ptr;

	ptr = f(lst->content);
	if (!ptr)
		return (NULL);
	temp = ft_lstnew(ptr);
	if (!temp)
	{
		del(ptr);
		return (NULL);
	}
	return (temp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*end;
	t_list	*temp;
	t_list	*ret;

	ret = NULL;
	end = NULL;
	while (lst)
	{
		temp = new_list_item(lst, f, del);
		if (!temp)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&end, temp);
		if (!ret)
			ret = end;
		else
			end = end->next;
		lst = lst->next;
	}
	return (ret);
}
