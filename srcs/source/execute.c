/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:25:24 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/27 16:07:15 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Prints an operation
*/

static	void	print_op(t_op operation)
{
	const char	*flutes[OP_COUNT] = {
	[e_sa] = "sa\n",
	[e_sb] = "sb\n",
	[e_ra] = "ra\n",
	[e_rb] = "rb\n",
	[e_rra] = "rra\n",
	[e_rrb] = "rrb\n",
	[e_pa] = "pa\n",
	[e_pb] = "pb\n",
	[e_ss] = "ss\n",
	[e_rr] = "rr\n",
	[e_rrr] = "rrr\n",
	};

	(void)flutes[operation];
	ft_putstr_fd(flutes[operation], 1);
}

/*
** Updates stack size counters
*/

static	void	update_stack_size(t_stacks *ab, t_op operation)
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

void	execute(t_stacks *ab, t_op operation)
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

	update_stack_size(ab, operation);
	exectable[operation](ab);
	print_op(operation);
}
