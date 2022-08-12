/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:41:15 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/02/08 14:31:17 by simoncleerd   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	update_remainder(char **remainder, int read_return)
{
	size_t	lenline;
	size_t	remainder_size;
	char	*temp;

	if (read_return == 0)
		return (0);
	lenline = ft_strclen(*remainder, '\0');
	temp = ft_strndup((*remainder), lenline);
	if (!temp)
		return (0);
	remainder_size = ft_strclen(*remainder, '\n') + 1;
	free(*remainder);
	*remainder = ft_strndup(&temp[remainder_size], \
								lenline - (remainder_size - 1));
	free(temp);
	return (read_return);
}

int	read_till_newline(char **remainder, int fd)
{
	char	*str;
	int		result;

	result = 1;
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (0);
	while (result > 0 && remainder)
	{
		result = read(fd, str, BUFFER_SIZE);
		if (result < 0 || (result == 0 && (ft_strclen(*remainder, '\0') == 0)))
		{
			free(*remainder);
			*remainder = NULL;
			break ;
		}
		*remainder = ft_strjoin(*remainder, str);
		if (!remainder)
			break ;
		ft_memset(str, 0, ft_strclen(str, '\0'));
		if (ft_strchr(*remainder, '\n') || result == 0)
			break ;
	}
	free(str);
	return (result);
}

char	*ft_get_next_line(const int fd)
{
	static char	*remainder = NULL;
	char		*destination;
	int			read_return;

	read_return = 1;
	destination = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
		remainder = ft_strndup("", 0);
	if (!ft_strchr(remainder, '\n'))
		read_return = read_till_newline(&remainder, fd);
	if (remainder)
		destination = ft_strndup(remainder, ft_strclen(remainder, '\n') + 1);
	if (read_return > 0)
		read_return = update_remainder(&remainder, read_return);
	if (read_return == 0 && remainder)
	{
		free(remainder);
		remainder = NULL;
	}
	return (destination);
}
