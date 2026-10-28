/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: simoncleerdin <simoncleerdin@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:06:04 by simoncleerd   #+#    #+#                 */
/*   Updated: 2022/02/08 14:09:18 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t n)
{
	char	*str;

	str = ft_calloc(n + 1, sizeof(char));
	return (str);
}
