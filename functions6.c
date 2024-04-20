/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:03:20 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 10:44:59 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_zero(const char *str, int i, int j)
{
	if (str[i + 1] == '.' || str[i + 1] == '0')
	{
		if (str[i + 2 + j] == 'd' || str[i + 2 + j] == 'i' || str[i + 2
				+ j] == 'x' || str[i + 2 + j] == 'X' || str[i + 2 + j] == 'u'
			|| str[i + 2 + j] == 's')
			return (1);
	}
	if (str[i + 1] == '-' || str[i + 1] == ' ' || (str[i + 1] >= '1' && str[i
				+ 1] <= '9'))
	{
		if (str[i + j + 2] == 's' || str[i + j + 2] == 'd' || str[i + j
				+ 2] == 'i' || str[i + j + 2] == 'p' || str[i + j + 2] == 'u'
			|| str[i + j + 2] == 'x' || str[i + j + 2] == 'X' || str[i + j
				+ 2] == 'c')
			return (1);
	}
	if ((str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x')
		|| (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X')
		|| (str[i] == '%' && str[i + 1] == ' ' && (str[i + 2] == 'd' || str[i
					+ 2] == 'i')) || (str[i] == '%' && str[i + 1] == '+'
			&& (str[i + 2] == 'd' || str[i + 2] == 'i')))
		return (1);
	return (0);
}

char	*ft_decimal_space(char *print, int nb, int nb_space)
{
	char	*result;

	result = ft_itoa(nb);
	if (!result)
		return (NULL);
	if (nb_space >= ft_strlen(result))
		print = ft_realloc(print, nb_space);
	while (nb_space-- > ft_strlen(result))
		print = ft_strcat(print, " ");
	print = ft_decimal(print, nb, 1);
	return (free(result), print);
}

char	*ft_decimal_space2(char *print, int nb)
{
	if (nb >= 0)
	{
		print = ft_realloc(print, 1);
		if (!print)
			return (NULL);
		print = ft_strcat(print, " ");
	}
	print = ft_decimal(print, nb, 1);
	return (print);
}

char	*ft_decimal_zero2(char *print, int nb, int nb_zero)
{
	char	*result;

	result = ft_itoa(nb);
	if (!result)
		return (NULL);
	print = ft_decimal(print, nb, 1);
	if (!print)
		return (free(result), NULL);
	if (nb_zero > ft_strlen(result))
	{
		print = ft_realloc(print, nb_zero);
		if (!print)
			return (free(result), NULL);
		while (nb_zero-- - ft_strlen(result) > 0)
			print = ft_strcat(print, " ");
	}
	return (free(result), print);
}

char	*ft_space_string(char *print, char *str, int nb_space)
{
	if (!str)
	{
		print = ft_realloc(print, 6);
		if (!print)
			return (NULL);
		print = ft_strcat(print, "(null)");
		return (print);
	}
	if (nb_space > ft_strlen(str))
		print = ft_realloc(print, nb_space);
	else
		print = ft_realloc(print, ft_strlen(str));
	if (!print)
		return (NULL);
	while (nb_space-- - ft_strlen(str) > 0)
		print = ft_strcat(print, " ");
	print = ft_strcat(print, str);
	return (print);
}
