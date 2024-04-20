/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:34:42 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 11:12:45 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_zero1(char *print, int nb_zero, char *result, int sign)
{
	print = ft_realloc(print, nb_zero + sign);
	if (!print)
		return (free(result), NULL);
	if (sign == 1)
		print = ft_strcat(print, "-");
	while (nb_zero-- - sign > ft_strlen(result))
		print = ft_strcat(print, "0");
	print = ft_strcat(print, result);
	return (print);
}

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

char	*ft_format_dot(char *print, const char *str, int i, va_list args)
{
	int	nb_zero;
	int	j;

	j = 0;
	nb_zero = 0;
	if (str[i + 1] >= '1' && str[i + 1] <= '9')
		nb_zero = str[i + 1] - '0';
	while (str[i + j + 2] >= '0' && str[i + j + 2] <= '9')
		nb_zero = (nb_zero * 10) + (str[i + j++ + 2] - '0');
	if ((str[i + j + 2] == 'd' || str[i + j + 2] == 'i') && str[i + 1] == '.')
		print = ft_decimal_zero1(print, (int)va_arg(args, int), nb_zero);
	if (str[i + j + 2] == 'x' && (str[i + 1] == '0' || str[i + 1] == '.'))
		print = ft_hexa_lowercase_zero(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 'X' && (str[i + 1] == '0' || str[i + 1] == '.'))
		print = ft_hexa_uppercase_zero(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 'u' && (str[i + 1] == '0' || str[i + 1] == '.'))
		print = ft_unsigned_zero(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	if (str[i + j + 2] == 's' && str[i + 1] == '.')
		print = ft_string_zero(print, (char *)va_arg(args, char *), nb_zero);
	return (print);
}

char	*ft_format_zero(char *print, const char *str, int i, va_list args)
{
	int	nb_zero;
	int	j;

	j = 0;
	nb_zero = 0;
	while (str[i + j + 2] >= '0' && str[i + j + 2] <= '9')
		nb_zero = (nb_zero * 10) + (str[i + j++ + 2] - '0');
	if ((str[i + j + 2] == 'd' || str[i + j + 2] == 'i') && str[i + 1] == '0')
		print = ft_decimal_zero(print, (int)va_arg(args, int), nb_zero);
	if (str[i + j + 2] == 'u' && str[i + 1] == '0')
		print = ft_unsigned_zero(print, (int)va_arg(args, int), nb_zero);
	if (str[i + j + 2] == 'x' && str[i + 1] == '0')
		print = ft_hexa_lowercase_zero(print, (int)va_arg(args, int), nb_zero);
	if (str[i + j + 2] == 'X' && str[i + 1] == '0')
		print = ft_hexa_uppercase_zero(print, (int)va_arg(args, int), nb_zero);
	return (print);
}

char	*ft_space_format(char *print, const char *str, int i, va_list args)
{
	int	nb_zero;
	int	j;

	j = ft_increment(str, i);
	nb_zero = ft_nb_zero(str, i);
	if (str[i + j + 2] == 's')
		print = ft_space_string(print, (char *)va_arg(args, char *), nb_zero);
	else if ((str[i + 2] == 'd' || str[i + 2] == 'i') && str[i + 1] == ' ')
		print = ft_decimal_space2(print, (int)va_arg(args, int));
	else if (str[i + j + 2] == 'd' || str[i + j + 2] == 'i')
		print = ft_decimal_space(print, (int)va_arg(args, int), nb_zero);
	else if (str[i + j + 2] == 'c')
		print = ft_space_char(print, (char)va_arg(args, int), nb_zero);
	else if (str[i + j + 2] == 'p')
		print = ft_space_pointer(print, (void *)va_arg(args, void *), nb_zero);
	else if (str[i + j + 2] == 'u')
		print = ft_space_unsigned(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	else if (str[i + j + 2] == 'x')
		print = ft_space_hexa_lowercase(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	else if (str[i + j + 2] == 'X')
		print = ft_space_hexa_uppercase(print, (unsigned int)va_arg(args,
					unsigned int), nb_zero);
	return (print);
}
