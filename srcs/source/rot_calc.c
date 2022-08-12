/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 15:32:21 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:59:58 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	executes operations on seperate based on the data from t_pot
*/

void	run_op_single(t_stacks *ab, t_pot *op)
{
	while (op->rot_a != 0 || op->rot_b != 0)
	{
		if (op->rot_a > 0)
		{
			execute(ab, e_ra);
			op->rot_a--;
		}
		else if (op->rot_b > 0)
		{
			execute(ab, e_rb);
			op->rot_b--;
		}
		else if (op->rot_a < 0)
		{
			execute(ab, e_rra);
			op->rot_a++;
		}
		else if (op->rot_b < 0)
		{
			execute(ab, e_rrb);
			op->rot_b++;
		}
	}
}

/*
**	executes operations on both stacks based on the data from t_pot
*/

void	run_op_double(t_stacks *ab, t_pot *op)
{
	while (op->rot_a != 0 || op->rot_b != 0)
	{
		if (op->rot_b > 0 && op->rot_a > 0)
		{
			execute(ab, e_rr);
			op->rot_a--;
			op->rot_b--;
		}
		else if (op->rot_b < 0 && op->rot_a < 0)
		{
			execute(ab, e_rrr);
			op->rot_a++;
			op->rot_b++;
		}
		if ((op->rot_a == 0 && op->rot_b != 0) || \
			(op->rot_a != 0 || op->rot_b == 0))
			run_op_single(ab, op);
	}
}

/*
**	Calculates rotation counts based on stack A & Bs current state
**	Chooses most efficient operations to next push
**	Executes operations till next push
*/

void	rot_calc(t_stacks *ab)
{
	t_pot	*pot;
	t_pot	*final;

	pot = get_stack_data(ab);
	if (pot == NULL)
		return ;
	final = choose_pot(pot);
	if ((final->rot_b > 0 && final->rot_a > 0) || \
		(final->rot_b < 0 && final->rot_a < 0))
		run_op_double(ab, final);
	else
		run_op_single(ab, final);
	execute(ab, e_rb);
	execute(ab, e_pb);
	delete_tpots(&pot);
}
