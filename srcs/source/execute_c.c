/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 11:33:11 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:49:31 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Updates stack size counters
*/

static	void	update_stack_size_c(t_stacks *ab, t_op operation)
{
	if (operation == e_pa)
	{
		ab->size_a++;
		ab->size_b--;
	}
	else if (operation == e_pb)
	{
		ab->size_a--;
		ab->size_b++;
	}
}

/*
** Executes and prints the operation
** Updates stack size counters
*/

void	execute_c(t_stacks *ab, t_op operation)
{
	const t_operation	exectable[OP_COUNT] = {
	[e_sa] = &swap_a,
	[e_sb] = &swap_b,
	[e_ra] = &rotate_a,
	[e_rb] = &rotate_b,
	[e_rra] = &reverse_rotate_a,
	[e_rrb] = &reverse_rotate_b,
	[e_pa] = &push_a,
	[e_pb] = &push_b,
	[e_ss] = &ss,
	[e_rr] = &rr,
	[e_rrr] = &rrr,
	};

	update_stack_size_c(ab, operation);
	exectable[operation](ab);
}
