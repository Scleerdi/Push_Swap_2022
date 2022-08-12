/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dup_stack.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:16 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:47:52 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Duplicates stacks A and B
*/

static	t_stack	*dup_astack(t_stack const *stack)
{
	t_stack	*dest_tail;
	t_stack	*dest_head;

	if (stack != NULL)
	{
		dest_head = create_node(stack->data);
		if (dest_head == NULL)
			return (NULL);
		dest_tail = dest_head;
		stack = stack->next;
		while (stack != NULL)
		{
			dest_tail->next = create_node(stack->data);
			if (dest_tail->next == NULL)
			{
				del_stacks(&dest_head, NULL);
				return (NULL);
			}
			dest_tail = dest_tail->next;
			stack = stack->next;
		}
		return (dest_head);
	}
	return (NULL);
}

void	dup_stack(t_stacks const *ab, t_stacks *dup_ab)
{
	dup_ab->size_a = ab->size_a;
	dup_ab->size_b = ab->size_b;
	dup_ab->lead_a = ab->lead_a;
	dup_ab->lead_b = ab->lead_b;
	dup_ab->a = dup_astack(ab->a);
	dup_ab->b = dup_astack(ab->b);
}
