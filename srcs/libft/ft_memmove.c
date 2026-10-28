/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 12:20:43 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/02/08 16:37:10 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	int		x;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	x = -1;
	i = len - 1;
	s1 = (char *)dst;
	s2 = (char *)src;
	if (s1 < s2)
	{
		x = 1;
		i = 0;
	}
	while (len)
	{
		s1[i] = s2[i];
		i += (1 * x);
		len--;
	}
	return (s1);
}
