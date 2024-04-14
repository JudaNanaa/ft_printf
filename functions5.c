/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:34:42 by madamou           #+#    #+#             */
/*   Updated: 2024/04/14 20:49:35 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_zero(char *print, int nb_zero, char *result, int sign)
{
	print = ft_realloc(print, nb_zero + sign);
	if (!print)
		return (free(result), NULL);
	if (sign == 1)
		print = ft_strcat(print, "-");
	while (nb_zero-- > ft_strlen(result))
		print = ft_strcat(print, "0");
	print = ft_strcat(print, result);
	return (print);
}

char	*ft_fill_zero1(char *print, int nb_zero, char *result, int sign)
{
	print = ft_realloc(print, nb_zero);
	if (!print)
		return (free(result), NULL);
	if (sign == 1)
		print = ft_strcat(print, "-");
	while (nb_zero-- - sign > ft_strlen(result))
		print = ft_strcat(print, "0");
	print = ft_strcat(print, result);
	return (print);
}

char	*ft_format_if_zero(const char *str, int i, char *print, va_list args)
{
	int	nb_zero;
	int	j;

	j = 0;
	nb_zero = 0;
	while (str[i + j + 2] >= '0' && str[i + j + 2] <= '9')
		nb_zero = (nb_zero * 10) + (str[i + j++ + 2] - '0');
	if ((str[i + j + 2] == 'd' || str[i + j + 2] == 'i') && str[i + 1] == '.')
		print = ft_decimal_zero(print, (int)va_arg(args, int), nb_zero);
	if ((str[i + j + 2] == 'd' || str[i + j + 2] == 'i') && str[i + 1] == '0')
		print = ft_decimal_zero1(print, (int)va_arg(args, int), nb_zero);
	if (str[i + j + 2] == 'x')
		print = ft_hexa_lowercase_zero(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 'X')
		print = ft_hexa_uppercase_zero(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 'u')
		print = ft_unsigned_zero(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 's' && str[i + 1] == '.')
		print = ft_string_zero(print, (char *)va_arg(args, char *), nb_zero);
	if (str[i] == '%' && str[i + 1] == ' ')
	{
		if (str[i + j + 2] == 's')
			print = ft_string_space(print, (char *)va_arg(args, char *),
					nb_zero);
	}
	if (str[i] == '%' && str[i + 1] == '-')
	{
		if (str[i + j + 2] == 's')
			print = ft_string_space1(print, (char *)va_arg(args, char *),
					nb_zero);
		if ((str[i + j + 2] == 'd' || str[i + j + 2] == 'i'))
			print = ft_decimal_zero2(print, (int)va_arg(args, int), nb_zero);
	}
	return (print);
}

char	*ft_strcat(char *print, char *src)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(print);
	j = 0;
	while (src[j])
	{
		print[i++] = src[j++];
		ft_len_print(1);
	}
	print[i] = '\0';
	return (print);
}

int	ft_check_basic(const char *str, int i)
{
	if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
			|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
			|| str[i + 1] == 'p'))
		return (1);
	return (0);
}
