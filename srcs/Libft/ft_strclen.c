/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: simoncleerdin <simoncleerdin@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:23:33 by simoncleerd   #+#    #+#                 */
/*   Updated: 2022/02/08 14:24:16 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *str, char x)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != x)
		i++;
	return (i);
}
