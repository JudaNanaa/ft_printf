/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:12:36 by madamou           #+#    #+#             */
/*   Updated: 2024/04/09 06:55:10 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	free(s);
}

char	*ft_strcat(char *print, char *src)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(print);
	j = 0;
	while (src[j])
		print[i++] = src[j++];
	print[i] = '\0';
	return (print);
}

char	*ft_check_if_format(const char *str, int i, char *print, va_list args)
{
	if (str[i] == '%' && str[i + 1] == 'c')
		print = ft_char(print, (int)va_arg(args, int));
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

char *ft_format_if_hashtag(const char *str, int i, char *print, va_list args)
{
	if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x')
		print = ft_hexa_lowercase(print, (unsigned int)va_arg(args,
					unsigned int), 2);
	if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X')
		print = ft_hexa_uppercase(print, (unsigned int)va_arg(args,
					unsigned int), 2);
	return (print);
}

char *ft_format_if_space(const char *str, int i, char *print, va_list args)
{
	if (str[i] == '%' && str[i + 1] == ' ' && (str[i + 2] == 'd'
				|| str[i + 2] == 'i'))
		print = ft_decimal(print, (int)va_arg(args, int), 2);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	static va_list	args;
	char			*print;
	int				i;

	i = -1;
	print = malloc(sizeof(char));
	print[0] = '\0';
	va_start(args, str);
	while (str[++i] && print)
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
				|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
				|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
				|| str[i + 1] == 'p'))
		{
			print = ft_check_if_format(str, i, print, args);
			i += 2;
		}
		if ((str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x')
				|| (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X')
				|| (str[i] == '%' && str[i + 1] == ' ' && (str[i + 2] == 'd'
				|| str[i + 2] == 'i')))
		{
			print = ft_format_if_hashtag(str, i, print, args);
			print = ft_format_if_space(str, i, print, args);
			i += 3;
		}
		if (!print)
			return (0);
		print = ft_str_to_print(print, str[i]);
		if (!print)
			return (0);
	}
	return (va_end(args), i = ft_strlen(print), ft_putstr(print), i);
}

int	main(void)
{
	ft_printf("%#X, %#x , % i \n", 42 , 42, 42);
	printf("%#X, %#x , % i \n", 42 , 42, 42);
}