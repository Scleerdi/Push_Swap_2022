/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_num_len.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: simoncleerdin <simoncleerdin@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:08:33 by simoncleerd   #+#    #+#                 */
/*   Updated: 2022/07/25 16:42:17 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_num_len(int n)
{
	int	len;

	len = 1;
	if (n == 2147483647)
		return (10);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}
