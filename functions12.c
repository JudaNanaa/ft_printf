/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions12.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:33:02 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 20:33:21 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_lowercase_zero(char *print, unsigned int nb, int nb_zero)
{
	char	*result;
	int		len_result;
	char	*base;

	base = "0123456789abcdef";
	result = ft_itoa_base(nb, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	if (len_result < nb_zero)
	{
		print = ft_realloc(print, nb_zero);
		if (!print)
			return (free(result), NULL);
		while (nb_zero-- > len_result)
			print = ft_strcat(print, "0");
		print = ft_strcat(print, result);
	}
	else
		print = ft_hexa_lowercase(print, nb, 1);
	return (free(result), print);
}

char *ft_format_percent(char *print, const char *str, int i)
{
	int j;

	j = ft_increment(str, i);
	if (str[i + j + 2] == '%')
		print = ft_char(print, '%');
	return (print);
}

int ft_check_for_increment(const char *str, int i, int j)
{
	if ((str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x')
		|| (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X')
		|| (str[i] == '%' && str[i + 1] == ' ' && (str[i + 2] == 'd' || str[i
					+ 2] == 'i')) || (str[i] == '%' && str[i + 1] == '+'
			&& (str[i + 2] == 'd' || str[i + 2] == 'i')))
		return (1);
	if (str[i + j + 2] == '%' && (str[i + 1] >= '1' && str[i + 1] <= '9'))
		return (1);
	return (0);
}
