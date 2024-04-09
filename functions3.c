/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:02:12 by madamou           #+#    #+#             */
/*   Updated: 2024/04/09 19:09:25 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_moulinette(char *result, unsigned long long int nb, int size,
		char *base)
{
	if (nb >= (unsigned long long int)ft_strlen(base))
	{
		ft_moulinette(result, nb / ft_strlen(base), size - 1, base);
		ft_moulinette(result, nb % ft_strlen(base), size, base);
	}
	if (nb < (unsigned long long int)ft_strlen(base))
	{
		result[size - 1] = base[nb];
	}
}

char	*ft_itoa_long_long(unsigned long long int nb, char *base)
{
	int		size;
	char	*result;
	int		len_base;

	len_base = ft_strlen(base);
	size = ft_size_malloc(nb, len_base);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_moulinette(result, nb, size, base);
	result[size] = '\0';
	return (result);
}

char	*ft_pointer(char *print, void *ptr)
{
	unsigned long long int	true_ptr;
	char					*result;
	int						len_result;
	char					*base;

	base = "0123456789abcdef";
	true_ptr = (unsigned long long int)ptr;
	result = ft_itoa_long_long(true_ptr, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	print = ft_realloc(print, len_result + 2);
	if (!print)
		return (NULL);
	print = ft_strcat(print, "0x");
	print = ft_strcat(print, result);
	return (free(result), print);
}

char	*ft_decimal_zero(char *print, int nb, int nb_zero)
{
	char	*result;
	int		len_result;
	int sign;

	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	result = ft_itoa(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	if (len_result + sign < nb_zero)
	{
		print = realloc(print, nb_zero);
		if (!print)
			return (NULL);
		if (sign == 1)
			print = ft_strcat(print, "-");
		while (nb_zero-- - sign > len_result)
			print = ft_strcat(print, "0");
		print = ft_strcat(print, result);
	}
	else
		print = ft_decimal(print, nb, 1);
	return (print);
}