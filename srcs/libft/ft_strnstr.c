/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 14:22:39 by scleerdi      #+#    #+#                 */
/*   Updated: 2021/11/16 16:05:03 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needlelen;
	size_t		i;

	i = 0;
	if (!needle)
		return (NULL);
	needlelen = ft_strlen(needle);
	if ((needle[0]) == '\0')
		return ((char *)haystack);
	while ((i + needlelen - 1) < len && haystack[i] != '\0')
	{
		if (ft_strnequ(&haystack[i], needle, needlelen))
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
