/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 16:09:47 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 17:15:27 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned int n, int fd)
{
	char	*s;

	s = ft_itoa_base(n, 8);
	return (write(fd, s, ft_strlen(s)));
}
