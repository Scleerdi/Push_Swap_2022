/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 15:59:46 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/27 14:52:52 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conv_ex(long nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char	*ft_itoa_base(long value, int base)
{
	int		i;
	long	tmp;
	char	*str;

	tmp = ft_abs(value);
	i = ft_num_len(tmp);
	str = calloc(i + 1, sizeof(char));
	if (value < 0)
	{
		value *= -1;
		str[0] = '-';
	}
	if (!str)
		return (NULL);
	while (i >= 0 || str[i - 1] != '-')
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
}
