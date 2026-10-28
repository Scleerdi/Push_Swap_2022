/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 12:40:37 by scleerdi      #+#    #+#                 */
/*   Updated: 2021/11/11 15:24:25 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		if (del)
			del((*lst)->content);
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = NULL;
}
