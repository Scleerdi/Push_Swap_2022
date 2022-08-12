/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 17:02:09 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/08/12 15:30:08 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int		r;
	char	*st1;
	char	*st2;

	if (!s1 || !s2)
		return (0);
	st1 = (char *)s1;
	st2 = (char *)s2;
	r = ft_strcmp(st1, st2);
	if (r != 0)
		return (0);
	else
		return (1);
}
