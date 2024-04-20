/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions12.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:33:02 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 12:33:41 by madamou          ###   ########.fr       */
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
