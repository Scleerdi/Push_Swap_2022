/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bucket_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:25:49 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:44:51 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find location of ab->lead_b for efficient rotating
*/

static int	locate_temp_head_b(t_stacks *ab)
{
	int			i;
	t_stacks	dup_ab;
	t_stacks	hold_ab;

	i = 0;
	dup_stack(ab, &dup_ab);
	hold_ab = dup_ab;
	if (dup_ab.a == NULL || dup_ab.b == NULL)
		return (1);
	while (dup_ab.b->next && dup_ab.b->data != ab->lead_b)
	{
		dup_ab.b = dup_ab.b->next;
		i++;
	}
	del_stacks(&hold_ab.a, &hold_ab.b);
	return (i);
}

/*
** Gets called when head of A is larger than lead_b
** If lead_b is the head of B, push A to B
** else rotate B until lead_b is at the head, and push A to B
*/

static void	temp_top_b(t_stacks *ab)
{
	int	loc;

	loc = locate_temp_head_b(ab);
	if (loc == 0)
	{
		execute(ab, e_pb);
		return ;
	}
	else if (loc > ab->size_b / 2)
		while (ab->b->data != ab->lead_b)
			execute(ab, e_rrb);
	else
		while (ab->b->data != ab->lead_b)
			execute(ab, e_rb);
	execute(ab, e_pb);
}

/*
** If the head of A is lead_a rotate it away
** else if head of A is smaller than head of B, and head of A is larger than
** 		next value of B, rotate B and push A to B
** else if head of A is larger than lead_b, rotate lead_b to the top,
** 		and push A to B
** else call rot_calc
*/

static void	check_conditions(t_stacks *ab)
{
	if (ab->a->data == ab->lead_a)
		execute(ab, e_ra);
	else if (ab->a->data != ab->lead_a && ab->size_b == 1 && \
		ab->a->data > ab->b->data)
		execute(ab, e_pb);
	else if (ab->a->data < ab->b->data && ab->a->data > ab->b->next->data)
	{
		execute(ab, e_rb);
		execute(ab, e_pb);
	}
	else if (ab->a->data > ab->lead_b)
		temp_top_b(ab);
	else
		rot_calc(ab);
}

/*
**	Keeps track of the highest Int on stack B
*/

static void	set_lead_b(t_stacks *ab)
{
	if (ab->b && ab->b->data > ab->lead_b)
		ab->lead_b = ab->b->data;
}

/*
**	Calls push_lowest_value_to_b that passes lowest Data from stack A to stack B
**	Calls get_highest_value_from_a that marks The highest Data on stack A
**	Calls set_lead_b which keeps track of the Highest Data on stack B
**	Calls check_conditions which executes the next best course of operation
**	Calls push_all_b_to_a when size_a is 1
*/

void	bucket_sort(t_stacks *ab)
{
	push_lowest_value_to_b(ab);
	ab->lead_a = get_highest_value_from_a(ab);
	while (ab->size_a > 1)
	{
		set_lead_b(ab);
		check_conditions(ab);
	}
	push_all_b_to_a(ab);
}
