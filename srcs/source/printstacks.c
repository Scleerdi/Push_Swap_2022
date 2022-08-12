/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:42 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/27 16:08:21 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	print_list(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack)
		return ;
	while (current != NULL)
	{
		ft_putnbr_fd(current->data, 1);
		ft_putchar_fd('\n', 1);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
}

/*
** Print stacks for debug purposes
*/

void	printstacks(t_stack *a, t_stack *b)
{
	ft_putstr_fd("stack A:\n", 1);
	print_list(a);
	ft_putstr_fd("stack B:\n", 1);
	print_list(b);
}
