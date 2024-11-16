/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:48:43 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 04:50:16 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	ft_fill_itoa(char *result, unsigned long long int nb, int size,
		char *base)
{
	if (nb >= (unsigned long long int)ft_strlen(base))
	{
		ft_fill_itoa(result, nb / ft_strlen(base), size - 1, base);
		ft_fill_itoa(result, nb % ft_strlen(base), size, base);
	}
	if (nb < (unsigned long long int)ft_strlen(base))
		result[size - 1] = base[nb];
}

char	*ft_itoa_long_long(unsigned long long int nb, char *base)
{
	int		size;
	char	*result;
	int		len_base;

	len_base = ft_strlen(base);
	size = ft_size_malloc_long(nb, len_base);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_fill_itoa(result, nb, size, base);
	result[size] = '\0';
	return (result);
}

int	ft_size_malloc(long nb, int len_base)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb / len_base > 0)
	{
		nb = nb / len_base;
		size++;
	}
	return (size);
}

void	recursive_itoa(char *result, long nb, int size, char *base)
{
	if (nb < 0)
	{
		nb = -nb;
		result[0] = '-';
	}
	if (nb >= (long)ft_strlen(base))
	{
		recursive_itoa(result, nb / ft_strlen(base), size - 1, base);
		recursive_itoa(result, nb % ft_strlen(base), size, base);
	}
	if (nb < (long)ft_strlen(base))
		result[size - 1] = base[nb];
}

char	*ft_itoa_base(unsigned int nb, char *base)
{
	int		size;
	char	*result;
	int		len_base;

	len_base = ft_strlen(base);
	size = ft_size_malloc(nb, len_base);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	recursive_itoa(result, nb, size, base);
	result[size] = '\0';
	return (result);
}