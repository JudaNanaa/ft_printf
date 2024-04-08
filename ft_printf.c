/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:12:36 by madamou           #+#    #+#             */
/*   Updated: 2024/04/08 20:18:38 by madamou          ###   ########.fr       */
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
					unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'X')
		print = ft_hexa_uppercase(print, (unsigned int)va_arg(args,
					unsigned int));
	else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		print = ft_decimal(print, (int)va_arg(args, int));
	return (print);
}

int	ft_printf(const char *str, ...)
{
	static va_list	args;
	char			*print;
	int				i;

	i = -1;
	print = NULL;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
				|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
				|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
				|| str[i + 1] == 'p'))
		{
			print = ft_check_if_format(str, i, print, args);
			if (!print)
				return (0);
			i += 2;
		}
		print = ft_str_to_print(print, str[i]);
		if (!print)
			return (0);
	}
	return (va_end(args), i = ft_strlen(print), ft_putstr(print), i);
}

int	main(void)
{
	ft_printf("%#X\n", 42);
	printf("%#X\n", 42);
}
