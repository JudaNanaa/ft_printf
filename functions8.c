/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:41:05 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 10:42:00 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_lowercase_space(char *print, unsigned int nb, int nb_space)
{
	char	*result;
	int		len_result;

	result = ft_itoa_base(nb, "0123456789abcdef");
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	print = ft_hexa_lowercase(print, nb, 1);
	if (nb_space > len_result)
	{
		print = ft_realloc(print, nb_space - len_result);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - len_result > 0)
			print = ft_strcat(print, " ");
	}
	return (free(result), print);
}

char	*ft_space_hexa_lowercase(char *print, unsigned int nb, int nb_space)
{
	char	*result;
	int		len_result;

	result = ft_itoa_base(nb, "0123456789abcdef");
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	if (nb_space > len_result)
	{
		print = ft_realloc(print, nb_space - len_result);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - len_result > 0)
			print = ft_strcat(print, " ");
	}
	print = ft_hexa_lowercase(print, nb, 1);
	return (free(result), print);
}

char	*ft_hexa_uppercase_space(char *print, unsigned int nb, int nb_space)
{
	char	*result;
	int		len_result;

	result = ft_itoa_base(nb, "0123456789ABCDEF");
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	print = ft_hexa_uppercase(print, nb, 1);
	if (nb_space > len_result)
	{
		print = ft_realloc(print, nb_space - len_result);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - len_result > 0)
			print = ft_strcat(print, " ");
	}
	return (free(result), print);
}

char	*ft_space_hexa_uppercase(char *print, unsigned int nb, int nb_space)
{
	char	*result;
	int		len_result;

	result = ft_itoa_base(nb, "0123456789ABCDEF");
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	if (nb_space > len_result)
	{
		print = ft_realloc(print, nb_space - len_result);
		if (!print)
			return (free(result), NULL);
		while (nb_space-- - len_result > 0)
			print = ft_strcat(print, " ");
	}
	print = ft_hexa_uppercase(print, nb, 1);
	return (free(result), print);
}

char	*ft_char_space(char *print, char c, int nb_space)
{
	print = ft_char(print, c);
	if (!print)
		return (NULL);
	if (nb_space > 1)
	{
		print = ft_realloc(print, nb_space - 1);
		if (!print)
			return (NULL);
		while (nb_space-- - 1 > 0)
			print = ft_strcat(print, " ");
	}
	return (print);
}
