/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 14:33:43 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/02/08 14:11:55 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*s2;

	j = 0;
	i = ft_strlen(s1);
	s2 = ft_strnew(i);
	if (!s2)
		return (NULL);
	while (i > j)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}
