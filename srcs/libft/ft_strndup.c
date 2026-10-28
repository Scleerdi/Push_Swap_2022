/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: simoncleerdin <simoncleerdin@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:24:55 by simoncleerd   #+#    #+#                 */
/*   Updated: 2022/07/20 17:15:27 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = ft_calloc(n + 1, sizeof(char));
	if (!s2)
		return (NULL);
	while (i < n && s1 != NULL)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
