/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 11:51:00 by scleerdi       #+#    #+#                */
/*   Updated: 2019/09/05 11:52:08 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_abs(intmax_t a)
{
	if (a < 0)
		a *= -1;
	return (a);
}
