/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   high.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:35 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 12:56:11 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine(t_stacks const *ab)
{
	int			head;
	t_stacks	dup_ab;
	t_stacks	hold_ab;

	head = ab->a->data;
	dup_stack(ab, &dup_ab);
	hold_ab = dup_ab;
	if (dup_ab.a == NULL)
		return (1);
	while (dup_ab.a)
	{
		if (dup_ab.a->data > head)
			head = dup_ab.a->data;
		dup_ab.a = dup_ab.a->next;
	}
	del_stacks(&hold_ab.a, &hold_ab.b);
	return (head);
}

static	int	locate(t_stacks const *ab, int head)
{
	int			i;
	t_stacks	dup_ab;
	t_stacks	hold_ab;

	i = 0;
	dup_stack(ab, &dup_ab);
	hold_ab = dup_ab;
	if (dup_ab.a == NULL)
		return (1);
	while (dup_ab.a->next && dup_ab.a->data != head)
	{
		dup_ab.a = dup_ab.a->next;
		i++;
	}
	del_stacks(&hold_ab.a, &hold_ab.b);
	return (i);
}

/*
** 1. Find the value of the highest integer in stack A
** 2. Find the position of the highest integer in stack A
*/

int	get_highest_value_from_a(t_stacks const *ab)
{
	int	head;
	int	loc_h;

	head = determine(ab);
	loc_h = locate(ab, head);
	return (head);
}
