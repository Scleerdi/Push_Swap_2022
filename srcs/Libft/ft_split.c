/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 15:20:24 by scleerdi      #+#    #+#                 */
/*   Updated: 2021/11/18 15:41:41 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	locate(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static int	count(char const *s, char c)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			x++;
		i++;
	}
	return (x);
}

static	char	**err_del(char **sv, int y)
{
	while (y > 0)
	{
		if (sv[y])
			free(sv[y]);
		y--;
	}
	free(sv);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		y;
	char	**sv;

	if (!s)
		return (NULL);
	sv = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!sv)
		return (NULL);
	i = 0;
	y = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			sv[y] = ft_substr(s, i, locate(s, c, i));
			if (!sv[y])
				return (err_del(sv, y));
			y++;
		}
		i++;
	}
	sv[y] = NULL;
	return (sv);
}
