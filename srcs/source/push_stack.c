/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:48 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:57:16 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	pushes list item from head of src to head of dst
*/

void	push_stack(t_stack **dst, t_stack **src)
{
	t_stack	*temp;

	temp = NULL;
	if ((*src) == NULL)
		return ;
	else if (*dst == NULL)
	{
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = NULL;
	}
	else
	{
		temp = *dst;
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = temp;
		(*dst)->next->next = temp->next;
	}
}

void	push_a(t_stacks *ab)
{
	push_stack(&ab->a, &ab->b);
}

void	push_b(t_stacks *ab)
{
	push_stack(&ab->b, &ab->a);
}
