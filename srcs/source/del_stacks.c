/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_stacks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:05 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:47:24 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Deletes and frees stacks A and B
*/

static	void	del_stack(t_stack **astack)
{
	t_stack	*trail;

	if (!astack)
		return ;
	while (*astack)
	{
		trail = *astack;
		*astack = (*astack)->next;
		ft_bzero(trail, sizeof(t_stack));
		free(trail);
	}
}

void	del_stacks(t_stack **astack_a, t_stack **astack_b)
{
	del_stack(astack_a);
	del_stack(astack_b);
}
