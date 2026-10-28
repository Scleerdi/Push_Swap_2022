/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: simoncleerdin <simoncleerdin@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:39:40 by simoncleerd   #+#    #+#                 */
/*   Updated: 2022/02/25 16:18:26 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(char f)
{
	if (f == 'c' || f == 's' || f == 'x' || f == 'X' \
	|| f == 'p' || f == 'd' || f == 'i' || f == 'u' \
	|| f == '%')
		return (1);
	return (0);
}

char	*handle_ptr(va_list args)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_utoa_base((va_arg(args, size_t)), 16);
	if (!ptr)
		return (NULL);
	if (ptr[0] == '0' && ptr != NULL)
	{
		free(ptr);
		return (ft_strdup("0x0"));
	}
	ptr = ft_strjoin("0x", ptr);
	while (ptr[i])
	{
		ptr[i] = ft_tolower(ptr[i]);
		i++;
	}
	return (ptr);
}

char	*handle_hex(va_list args, char f)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_utoa_base(va_arg(args, unsigned int), 16);
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (f == 'X')
			s[i] = ft_toupper(s[i]);
		else if (f == 'x')
			s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

int	get_arg(va_list args, char f)
{
	char	*str;
	int		r;

	if (f == '%')
		return (ft_putchar_fd('%', 1));
	if (f == 'c')
		return (ft_putchar_fd((va_arg(args, int)), 1));
	if (f == 's')
		return (ft_putstr_fd((va_arg(args, char *)), 1));
	if (f == 'i' || f == 'd')
		str = ft_itoa((va_arg(args, int)));
	if (f == 'u')
		str = ft_utoa_base((va_arg(args, unsigned int)), 10);
	if (f == 'x' || f == 'X')
		str = handle_hex(args, f);
	if (f == 'p')
		str = handle_ptr(args);
	if (str != NULL)
	{
		r = ft_putstr_fd(str, 1);
		free(str);
		return (r);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print;

	i = 0;
	print = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && check_flag(format[i + 1]))
		{
			print += get_arg(args, format[i + 1]);
			i += 2;
		}
		else
		{
			print += ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (print);
}
