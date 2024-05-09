/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:39:44 by madamou           #+#    #+#             */
/*   Updated: 2024/05/09 00:48:47 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string_space1(char *print, char *str, int nb_space)
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
	print = ft_strcatt(print, str);
	while (nb_space-- - ft_strlen1(str) > 0)
		print = ft_strcatt(print, " ");
	return (print);
}

char	*ft_pointer1(char *print, void *ptr, int nb_space)
{
	unsigned long long int	true_ptr;
	char					*result;

	true_ptr = (unsigned long long int)ptr;
	result = ft_itoa_long_long(true_ptr, "0123456789abcdef");
	if (!result)
		return (NULL);
	print = ft_pointer(print, ptr);
	if (true_ptr == 0 && nb_space > 5 && print)
	{
		print = ft_reallocc(print, nb_space - 5);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - 5 > 0)
			print = ft_strcatt(print, " ");
	}
	if (true_ptr != 0 && nb_space > (ft_strlen1(result) + 2) && print)
	{
		print = ft_reallocc(print, nb_space - (ft_strlen1(result) + 2));
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - (ft_strlen1(result) + 2) > 0)
			print = ft_strcatt(print, " ");
	}
	return (free(result), print);
}

char	*ft_space_pointer(char *print, void *ptr, int nb_space)
{
	unsigned long long int	true_ptr;
	char					*result;

	true_ptr = (unsigned long long int)ptr;
	result = ft_itoa_long_long(true_ptr, "0123456789abcdef");
	if (true_ptr == 0 && nb_space > 5)
	{
		print = ft_reallocc(print, nb_space - 5);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - 5 > 0)
			print = ft_strcatt(print, " ");
	}
	if (true_ptr != 0 && nb_space > (ft_strlen1(result) + 2))
	{
		print = ft_reallocc(print, nb_space - (ft_strlen1(result) + 2));
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - (ft_strlen1(result) + 2) > 0)
			print = ft_strcatt(print, " ");
	}
	if (!result)
		return (NULL);
	print = ft_pointer(print, ptr);
	return (free(result), print);
}

char	*ft_unsigned_space(char *print, unsigned int nb, int nb_space)
{
	char	*result;
	int		len_result;

	result = ft_itoa_unsigned(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	print = ft_unsigned(print, nb);
	if (!print)
		return (free(result), NULL);
	if (nb_space > len_result)
	{
		print = ft_reallocc(print, nb_space - len_result);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - len_result > 0)
			print = ft_strcatt(print, " ");
	}
	return (free(result), print);
}

char	*ft_space_unsigned(char *print, unsigned int nb, int nb_space)
{
	char	*result;
	int		len_result;

	result = ft_itoa_unsigned(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	if (nb_space > len_result)
	{
		print = ft_reallocc(print, nb_space - len_result);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - len_result > 0)
			print = ft_strcatt(print, " ");
	}
	print = ft_unsigned(print, nb);
	if (!print)
		return (free(result), NULL);
	return (free(result), print);
}
