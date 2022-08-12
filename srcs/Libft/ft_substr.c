/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 14:49:53 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/02/08 14:13:43 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		str_len;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (len > str_len)
		str = ft_strnew(str_len);
	else
		str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (start > str_len)
		return (str);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
