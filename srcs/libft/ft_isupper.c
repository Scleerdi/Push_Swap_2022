/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: simoncleerdin <simoncleerdin@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:04:06 by simoncleerd   #+#    #+#                 */
/*   Updated: 2022/02/08 16:33:39 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
