/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_pot_list_tools.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 14:10:38 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 13:38:01 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Calls function to allocate size of t_pot
**		and adds relevant information to it
*/

int	init_tpot(t_pot **head, int rot_a, int rot_b)
{
	t_pot	*new;

	new = create_tpot(rot_a, rot_b);
	if (!new)
		return (0);
	new->next = *head;
	*head = new;
	return (1);
}

/*
**	Allocates memory for the t_pot linked list item
*/

t_pot	*create_tpot(int rot_a, int rot_b)
{
	t_pot	*new;

	new = ft_memalloc(sizeof(t_pot));
	if (!new)
		return (NULL);
	new->rot_a = rot_a;
	new->rot_b = rot_b;
	return (new);
}

/*
**	Frees allocated memory after its purpose is served
*/

void	delete_tpots(t_pot **head)
{
	t_pot	*current;

	if (!(*head))
		return ;
	while ((*head))
	{
		current = *head;
		*head = (*head)->next;
		ft_bzero(current, sizeof(t_pot));
		free(current);
	}
}
