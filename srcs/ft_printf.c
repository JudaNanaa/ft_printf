/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:12:36 by madamou           #+#    #+#             */
/*   Updated: 2024/12/03 01:11:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdbool.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_printf	data;
	int			i;
	int			increment;

	i = 0;
	if (!str)
		return (-1);
	(ft_bzero(&data, sizeof(data)), va_start(args, str));
	data.print = true;
	data.fd = STDOUT_FILENO;
	while (str[i])
	{
		if (str[i] == '%')
		{
			increment = parse_flag(&str[++i], &data, args);
			if (increment == -1)
				return (va_end(args), -1);
			i += increment;
			continue ;
		}
		if (add_char_to_buffer(&data, str[i++]) == -1)
			return (va_end(args), -1);
	}
	return (va_end(args), flush_buffer(&data), data.nb_print);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list		args;
	t_printf	data;
	int			i;
	int			increment;

	i = 0;
	if (!str)
		return (-1);
	(ft_bzero(&data, sizeof(data)), va_start(args, str));
	data.print = true;
	data.fd = fd;
	while (str[i])
	{
		if (str[i] == '%')
		{
			increment = parse_flag(&str[++i], &data, args);
			if (increment == -1)
				return (va_end(args), -1);
			i += increment;
			continue ;
		}
		if (add_char_to_buffer(&data, str[i++]) == -1)
			return (va_end(args), -1);
	}
	return (va_end(args), flush_buffer(&data), data.nb_print);
}

char	*ft_sprintf(const char *str, ...)
{
	va_list		args;
	t_printf	data;
	int			i;
	int			increment;

	i = 0;
	if (!str)
		return (NULL);
	(ft_bzero(&data, sizeof(data)), va_start(args, str));
	data.print = false;
	while (str[i])
	{
		if (str[i] == '%')
		{
			increment = parse_flag(&str[++i], &data, args);
			if (increment == -1)
				return (va_end(args), NULL);
			i += increment;
			continue ;
		}
		if (add_char_to_buffer(&data, str[i++]) == -1)
			return (va_end(args), NULL);
	}
	return (va_end(args), flush_buffer(&data), data.str);
}

// int	main(void)
// {
// 	printf(" return (value == [%d]\n", printf("%.6i", -3)));
// 	printf(" return (value == [%d]\n", ft_printf("%.6i", -3)));
// }
