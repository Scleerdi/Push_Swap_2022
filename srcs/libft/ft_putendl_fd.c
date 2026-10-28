/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 14:21:37 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 17:28:15 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	int	r;

	r = 1;
	r += ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (r);
}
