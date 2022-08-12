/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_pot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 15:28:37 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:46:26 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Finds the lowest operation count till next push
*/

static int	op_count(t_pot *pot)
{
	return (ft_abs(pot->rot_a) + ft_abs(pot->rot_b));
}

t_pot	*choose_pot(t_pot *pot)
{
	t_pot	*final;
	int		f_ops;

	final = pot;
	while (pot)
	{
		f_ops = op_count(final);
		if (op_count(pot) < f_ops)
			final = pot;
		pot = pot->next;
	}
	return (final);
}
