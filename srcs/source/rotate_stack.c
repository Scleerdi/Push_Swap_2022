/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:13 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 13:00:29 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Rotates the stack
*/

static	void	rotate_stack(t_stack **stack, int size)
{
	t_stack	*current;
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	current = *stack;
	if (current == NULL || size == 1 || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	while (i < size && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	current->next = temp;
	temp->next = NULL;
}

void	rr(t_stacks *ab)
{
	rotate_a(ab);
	rotate_b(ab);
}

void	rotate_a(t_stacks *ab)
{
	rotate_stack(&ab->a, ab->size_a);
}

void	rotate_b(t_stacks *ab)
{
	rotate_stack(&ab->b, ab->size_b);
}
