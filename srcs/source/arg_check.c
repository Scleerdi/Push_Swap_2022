/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 11:58:40 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/18 15:49:46 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libft.h>

/*
**	Looks for duplicate input
*/

int	value_exists(t_stack *a, int data)
{
	if (a == NULL)
		return (0);
	if (a->data == data)
		return (1);
	return (value_exists(a->next, data));
}

int	arg_check(t_stack *a, int data, char *str)
{
	if (ft_a_is_int(str) == 1 && value_exists(a, data) == 0)
		return (0);
	return (1);
}
