/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:27:18 by madamou           #+#    #+#             */
/*   Updated: 2024/05/09 00:47:24 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reallocc(char *print, int len_realloc)
{
	char	*tmp;
	int		i;

	i = ft_len_print(2);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	tmp = ft_strcpyy(tmp, print);
	free(print);
	print = malloc(sizeof(char) * (i + len_realloc + 1));
	if (!print)
		return (free(tmp), NULL);
	print = ft_strcpyy(print, tmp);
	free(tmp);
	return (print);
}

char	*ft_string(char *print, char *str)
{
	if (!str)
	{
		print = ft_reallocc(print, 6);
		if (!print)
			return (NULL);
		print = ft_strcatt(print, "(null)");
		return (print);
	}
	print = ft_reallocc(print, ft_strlen1(str));
	if (!print)
		return (NULL);
	print = ft_strcatt(print, str);
	return (print);
}

char	*ft_unsigned(char *print, unsigned int nb)
{
	char	*result;
	int		len_result;

	result = ft_itoa_unsigned(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	print = ft_reallocc(print, len_result);
	if (!print)
		return (NULL);
	print = ft_strcatt(print, result);
	return (free(result), print);
}

char	*ft_hexa_lowercase(char *print, unsigned int nb, int cas)
{
	char	*result;
	int		len_result;
	char	*base;

	base = "0123456789abcdef";
	if (nb == 0)
		return (print = ft_reallocc(print, 1), ft_strcatt(print, "0"));
	result = ft_itoa_base(nb, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	if (cas == 2)
		len_result += 2;
	print = ft_reallocc(print, len_result);
	if (!print)
		return (NULL);
	if (cas == 2)
		print = ft_strcatt(print, "0x");
	print = ft_strcatt(print, result);
	return (free(result), print);
}

char	*ft_hexa_uppercase(char *print, unsigned int nb, int cas)
{
	char	*result;
	int		len_result;
	char	*base;

	base = "0123456789ABCDEF";
	if (nb == 0)
		return (print = ft_reallocc(print, 1), ft_strcatt(print, "0"));
	result = ft_itoa_base(nb, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	if (cas == 2)
		len_result += 2;
	print = ft_reallocc(print, len_result);
	if (!print)
		return (NULL);
	if (cas == 2)
		print = ft_strcatt(print, "0X");
	print = ft_strcatt(print, result);
	return (free(result), print);
}
