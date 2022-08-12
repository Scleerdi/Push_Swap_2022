/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 11:44:20 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 13:37:24 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if the stack its fed is sorted in ascending order
*/

int	stack_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
