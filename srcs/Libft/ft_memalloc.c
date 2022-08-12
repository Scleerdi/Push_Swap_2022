/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:01:52 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/08/12 15:35:32 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}
