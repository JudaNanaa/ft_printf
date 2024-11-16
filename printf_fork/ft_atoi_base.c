/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:56:16 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 16:09:34 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_in_charset(char c, char *str, int str_base)
{
	int i;

	i = 0;
	while (str[i] && i < str_base)
	{
		if (str[i] == ft_tolower(c))
			return (1);
		i++;
	}
	return (0);
}

int index_in_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ft_tolower(c))
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	char *base;
	int sign;
	long result;
	int index;

	index = 0;
	base = "0123456789abcdef";
	result = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		index++;
		if (str[0] == '-')
		sign = -1;
	}
	while (is_in_charset(str[index], base, str_base) == 1)
	{
		result = result * str_base;
		result = result + index_in_base(base, str[index]); 
		index++;
	}
	return (result *sign);
}