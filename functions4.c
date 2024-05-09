/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 06:52:03 by madamou           #+#    #+#             */
/*   Updated: 2024/05/09 00:47:57 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_uppercase_zero(char *print, unsigned int nb, int nb_zero)
{
	char	*result;
	int		len_result;
	char	*base;

	base = "0123456789ABCDEF";
	result = ft_itoa_base(nb, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	if (len_result < nb_zero)
	{
		print = ft_reallocc(print, nb_zero);
		if (!print)
			return (free(result), NULL);
		while (nb_zero-- > len_result)
			print = ft_strcatt(print, "0");
		print = ft_strcatt(print, result);
	}
	else
		print = ft_hexa_uppercase(print, nb, 1);
	return (free(result), print);
}

char	*ft_unsigned_zero(char *print, unsigned int nb, int nb_zero)
{
	char	*result;
	int		len_result;

	result = ft_itoa_unsigned(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	if (len_result < nb_zero)
	{
		print = ft_reallocc(print, nb_zero);
		if (!print)
			return (free(result), NULL);
		while (nb_zero-- > len_result)
			print = ft_strcatt(print, "0");
		print = ft_strcatt(print, result);
	}
	else
		print = ft_unsigned(print, nb);
	return (free(result), print);
}

char	*ft_string_zero(char *print, char *str, int nb_string)
{
	size_t	i;
	int		j;

	print = ft_reallocc(print, nb_string);
	if (!print)
		return (NULL);
	i = ft_strlen1(print);
	j = 0;
	while (str[j] && j < nb_string)
	{
		print[i++] = str[j++];
		ft_len_print(1);
	}
	print[i] = '\0';
	return (print);
}

int	ft_size_malloc_long(unsigned long long int nb, int len_base)
{
	int	size;

	size = 1;
	while (nb / len_base > 0)
	{
		nb = nb / len_base;
		size++;
	}
	return (size);
}

int	ft_len_print(int cas)
{
	static int	len;

	if (cas == 0)
		return (len = 0, len);
	if (cas == 1)
	{
		len++;
		return (len);
	}
	return (len);
}
