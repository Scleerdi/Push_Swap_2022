/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 14:07:26 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/02/08 14:02:36 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	fix_tot(long tot, long sign)
{
	if (tot > 2147483648)
		tot = -1;
	else
		tot = tot * (long)sign;
	if (tot < -2147483649)
		return (0);
	return (tot);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		tot;

	i = 0;
	sign = 1;
	tot = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		tot = tot * 10 + str[i] - '0';
		i++;
	}
	tot = fix_tot(tot, (long)sign);
	return ((int)tot);
}
