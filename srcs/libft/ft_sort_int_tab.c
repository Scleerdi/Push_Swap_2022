/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 13:46:31 by scleerdi       #+#    #+#                */
/*   Updated: 2019/10/08 13:49:04 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	double			temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		if (tab[i] < tab[i + 1])
			i++;
		else if (tab[i] == tab[i + 1])
			i++;
		else
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
	}
}
