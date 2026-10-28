/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: simoncleerdin <simoncleerdin@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:12:22 by simoncleerd   #+#    #+#                 */
/*   Updated: 2022/02/08 14:13:07 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
		i++;
	return (i);
}
