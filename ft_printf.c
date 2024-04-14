/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:12:36 by madamou           #+#    #+#             */
/*   Updated: 2024/04/14 21:03:25 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		free(s);
	}
}

char	*ft_check_if_format(const char *str, int i, char *print, va_list args)
{
	if (str[i] == '%' && str[i + 1] == 'c')
		print = ft_char(print, (char)va_arg(args, int));
	if (str[i] == '%' && str[i + 1] == '%')
		print = ft_char(print, '%');
	else if (str[i] == '%' && str[i + 1] == 's')
		print = ft_string(print, (char *)va_arg(args, char *));
	else if (str[i] == '%' && str[i + 1] == 'u')
		print = ft_unsigned(print, (unsigned int)va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'p')
		print = ft_pointer(print, (void *)va_arg(args, void *));
	else if (str[i] == '%' && str[i + 1] == 'x')
		print = ft_hexa_lowercase(print, (unsigned int)va_arg(args,
					unsigned int), 1);
	else if (str[i] == '%' && str[i + 1] == 'X')
		print = ft_hexa_uppercase(print, (unsigned int)va_arg(args,
					unsigned int), 1);
	else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		print = ft_decimal(print, (int)va_arg(args, int), 1);
	return (print);
}

char	*ft_format_bonus(const char *str, int i, char *print, va_list args)
{
	if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x')
		print = ft_hexa_lowercase(print, (unsigned int)va_arg(args,
					unsigned int), 2);
	if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X')
		print = ft_hexa_uppercase(print, (unsigned int)va_arg(args,
					unsigned int), 2);
	if (str[i] == '%' && str[i + 1] == ' ' && (str[i + 2] == 'd'
			|| str[i + 2] == 'i'))
		print = ft_decimal(print, (int)va_arg(args, int), 2);
	if (str[i] == '%' && str[i + 1] == '+' && (str[i + 2] == 'd'
			|| str[i + 2] == 'i'))
		print = ft_decimal(print, (int)va_arg(args, int), 3);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*print;
	int		i;
	int		j;

	i = 0;
	print = malloc(sizeof(char));
	print[0] = '\0';
	va_start(args, str);
	while (str[i] && print)
	{
		j = 0;
		if (ft_check_basic(str, i) == 1)
		{
			print = ft_check_if_format(str, i, print, args);
			i += 2;
		}
		else if (ft_check_bonus(str, i) == 1)
		{
			print = ft_format_bonus(str, i, print, args);
			i += 3;
		}
		else if (str[i] == '%' && (str[i + 1] == '0' || str[i + 1] == '.'
				|| str[i + 1] == ' ' || str[i + 1] == '-'))
		{
			print = ft_format_if_zero(str, i, print, args);
			while (str[i + 2 + j] >= '0' && str[i + 2 + j] <= '9')
				j++;
			if (ft_check_zero(str, i, j) == 1)
				i += j + 2 + 1;
		}
		else if (str[i])
			print = ft_str_to_print(print, str[i++]);
		if (!print)
			return (0);
	}
	return (va_end(args), ft_putstr(print), ft_len_print(2));
}

int	main(void)
{
	printf(" %d\n", printf(" %-100d ", 12));
	printf(" %d\n", ft_printf(" %-100d ", 12));
}
