/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:51:59 by madamou           #+#    #+#             */
/*   Updated: 2024/12/03 01:11:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
