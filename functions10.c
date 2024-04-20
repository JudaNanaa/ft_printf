/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:19:06 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 20:33:50 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_minus(char *print, const char *str, int i, va_list args)
{
	int	nb_zero;
	int	j;

	j = ft_increment(str, i);
	nb_zero = ft_nb_zero(str, i);
	if (str[i + j + 2] == 's')
		print = ft_string_space1(print, (char *)va_arg(args, char *), nb_zero);
	if ((str[i + j + 2] == 'd' || str[i + j + 2] == 'i'))
		print = ft_decimal_zero2(print, (int)va_arg(args, int), nb_zero);
	if (str[i + j + 2] == 'c')
		print = ft_char_space(print, (char)va_arg(args, int), nb_zero);
	if (str[i + j + 2] == 'p')
		print = ft_pointer1(print, (void *)va_arg(args, void *), nb_zero);
	if (str[i + j + 2] == 'u')
		print = ft_unsigned_space(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 'x')
		print = ft_hexa_lowercase_space(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 'X')
		print = ft_hexa_uppercase_space(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == '%')
		print = ft_char(print, '%');
	return (print);
}

char	*ft_format_hashtag(char *print, const char *str, int i, va_list args)
{
	if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x')
		print = ft_hexa_lowercase(print, (unsigned int)va_arg(args,
					unsigned int), 2);
	if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X')
		print = ft_hexa_uppercase(print, (unsigned int)va_arg(args,
					unsigned int), 2);
	return (print);
}

char	*ft_format_plus(char *print, const char *str, int i, va_list args)
{
	if (str[i] == '%' && str[i + 1] == '+' && (str[i + 2] == 'd' || str[i
				+ 2] == 'i'))
		print = ft_decimal(print, (int)va_arg(args, int), 3);
	return (print);
}

char	*ft_format_bonus(const char *str, int i, char *print, va_list args)
{
	if (str[i + 1] == '.')
		print = ft_format_dot(print, str, i, args);
	if (str[i + 1] == '0')
		print = ft_format_zero(print, str, i, args);
	if ((str[i + 1] == ' ' || (str[i + 1] >= '1' && str[i + 1] <= '9')))
		print = ft_space_format(print, str, i, args);
	if (str[i + 1] == '-')
		print = ft_format_minus(print, str, i, args);
	if (str[i + 1] == '#')
		print = ft_format_hashtag(print, str, i, args);
	if (str[i + 1] == '+')
		print = ft_format_plus(print, str, i, args);
	if (str[i + 1] >= '1' && str[i + 1] <= '9')
		print = ft_format_percent(print, str, i);
	return (print);
}
