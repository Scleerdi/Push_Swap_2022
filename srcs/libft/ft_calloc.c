/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 14:24:07 by scleerdi      #+#    #+#                 */
/*   Updated: 2021/11/26 11:48:31 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = (void *)malloc(size * count);
	if (!r)
		return (NULL);
	ft_bzero(r, (size * count));
	return (r);
}
