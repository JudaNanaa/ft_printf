/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:03:20 by madamou           #+#    #+#             */
/*   Updated: 2024/05/09 14:52:25 by madamou          ###   ########.fr       */
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
				+ 2] == 'c' || str[i + j + 2] == '%')
			return (1);
	}
	if (ft_check_for_increment(str, i, j) == 1)
		return (1);
	return (0);
}

char	*ft_decimal_space(char *print, int nb, int nb_space)
{
	char	*result;

	result = ft_itoa(nb);
	if (!result)
		return (NULL);
	if (nb_space >= ft_strlen1(result))
		print = ft_reallocc(print, nb_space);
	while (nb_space-- > ft_strlen1(result))
		print = ft_strcatt(print, " ");
	print = ft_decimal(print, nb, 1);
	return (free(result), print);
}

char	*ft_decimal_space2(char *print, int nb)
{
	if (nb >= 0)
	{
		print = ft_reallocc(print, 1);
		if (!print)
			return (NULL);
		print = ft_strcatt(print, " ");
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
	if (nb_zero > ft_strlen1(result))
	{
		print = ft_reallocc(print, nb_zero);
		if (!print)
			return (free(result), NULL);
		while (nb_zero-- - ft_strlen1(result) > 0)
			print = ft_strcatt(print, " ");
	}
	return (free(result), print);
}

char	*ft_space_string(char *print, char *str, int nb_space)
{
	if (!str)
	{
		print = ft_reallocc(print, 6);
		if (!print)
			return (NULL);
		print = ft_strcatt(print, "(null)");
		return (print);
	}
	if (nb_space > ft_strlen1(str))
		print = ft_reallocc(print, nb_space);
	else
		print = ft_reallocc(print, ft_strlen1(str));
	if (!print)
		return (NULL);
	while (nb_space-- - ft_strlen1(str) > 0)
		print = ft_strcatt(print, " ");
	print = ft_strcatt(print, str);
	return (print);
}
