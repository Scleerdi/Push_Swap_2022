/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finalize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:29 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:50:58 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arrange(t_stacks *ab, int head, int i)
{
	if (i > ab->size_b / 2)
		while (ab->b->data != head)
			execute(ab, e_rrb);
	else
		while (ab->b->data != head)
			execute(ab, e_rb);
	while (ab->b)
		execute(ab, e_pa);
}

static int	determine(t_stacks *ab)
{
	int			head;
	t_stacks	dup_ab;
	t_stacks	hold_ab;

	head = ab->b->data;
	dup_stack(ab, &dup_ab);
	hold_ab = dup_ab;
	if (dup_ab.a == NULL || dup_ab.b == NULL)
		return (1);
	while (dup_ab.b)
	{
		if (dup_ab.b->data > head)
			head = dup_ab.b->data;
		dup_ab.b = dup_ab.b->next;
	}
	del_stacks(&hold_ab.a, &hold_ab.b);
	return (head);
}

static int	locate(t_stacks *ab, int head)
{
	int			i;
	t_stacks	dup_ab;
	t_stacks	hold_ab;

	i = 0;
	dup_stack(ab, &dup_ab);
	hold_ab = dup_ab;
	if (dup_ab.a == NULL || dup_ab.b == NULL)
		return (1);
	while (dup_ab.b->next && dup_ab.b->data != head)
	{
		dup_ab.b = dup_ab.b->next;
		i++;
	}
	del_stacks(&hold_ab.a, &hold_ab.b);
	return (i);
}

/*
** Move the highest value of B to the top of the stack and push to A
** 1. Finding the highest value
** 2. Locating the position
** 3. Rotating it to the top
** 4. Pushing all of B to A
*/

void	push_all_b_to_a(t_stacks *ab)
{
	int	i;
	int	head;

	i = 0;
	head = determine(ab);
	if (ab->b->data != head)
		i = locate(ab, head);
	arrange(ab, head, i);
}
