/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_stack.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:01 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:58:04 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Rotates the stack in reverse
*/

static	void	reverse_rotate_stack(t_stack **stack, int size)
{
	t_stack	*previous;
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	if (current == NULL || size == 1)
		return ;
	while (i < size && current->next != NULL)
	{
		previous = current;
		current = current->next;
		i++;
	}
	previous->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	rrr(t_stacks *ab)
{
	reverse_rotate_a(ab);
	reverse_rotate_b(ab);
}

void	reverse_rotate_a(t_stacks *ab)
{
	reverse_rotate_stack(&ab->a, ab->size_a);
}

void	reverse_rotate_b(t_stacks *ab)
{
	reverse_rotate_stack(&ab->b, ab->size_b);
}
