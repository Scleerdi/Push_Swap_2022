/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 12:38:14 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/02/08 14:12:37 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	j = ft_strnlen(dst, size);
	if (j == size)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && (j + i + 1) < size)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (size > j)
		dst[i + j] = '\0';
	if (size < i + j)
		return (j + ft_strlen(src));
	return (j + ft_strlen(src));
}
