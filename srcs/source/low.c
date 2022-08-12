/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   low.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:34 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:56:23 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	place(t_stacks *ab, int tail, int loc_t)
{
	if (loc_t > ab->size_a / 2)
		while (ab->a->data != tail)
			execute(ab, e_rra);
	else
		while (ab->a->data != tail)
			execute(ab, e_ra);
	execute(ab, e_pb);
}

static int	determine(t_stacks const *ab)
{
	int			tail;
	t_stacks	dup_ab;
	t_stacks	hold_ab;

	tail = ab->a->data;
	dup_stack(ab, &dup_ab);
	hold_ab = dup_ab;
	if (dup_ab.a == NULL)
		return (1);
	while (dup_ab.a)
	{
		if (dup_ab.a->data < tail)
			tail = dup_ab.a->data;
		dup_ab.a = dup_ab.a->next;
	}
	del_stacks(&hold_ab.a, &hold_ab.b);
	return (tail);
}

static	int	locate(t_stacks const *ab, int tail)
{
	int			i;
	t_stacks	dup_ab;
	t_stacks	hold_ab;

	i = 0;
	dup_stack(ab, &dup_ab);
	hold_ab = dup_ab;
	if (dup_ab.a == NULL)
		return (1);
	while (dup_ab.a->next && dup_ab.a->data != tail)
	{
		dup_ab.a = dup_ab.a->next;
		i++;
	}
	del_stacks(&hold_ab.a, &hold_ab.b);
	return (i);
}

/*
** 1. Finds the lowest integer in stack A
** 2. Finds the location of the lowest integer in stack A
** 3. Rotates stack A until the lowest integer is at the top
** 4. Pushes lowest integer to stack B
*/

int	push_lowest_value_to_b(t_stacks *ab)
{
	int	tail;
	int	loc_t;

	tail = determine(ab);
	ab->lead_b = tail;
	loc_t = locate(ab, tail);
	place(ab, tail, loc_t);
	return (tail);
}
