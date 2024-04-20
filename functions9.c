/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:42:12 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 11:20:22 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_space_char(char *print, char c, int nb_space)
{
	if (nb_space > 1)
	{
		print = ft_realloc(print, nb_space - 1);
		if (!print)
			return (NULL);
		while (nb_space-- - 1 > 0)
			print = ft_strcat(print, " ");
	}
	print = ft_char(print, c);
	if (!print)
		return (NULL);
	return (print);
}

int	ft_give_good_increment(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + 2 + j] >= '0' && str[i + 2 + j] <= '9')
		j++;
	if (ft_check_zero(str, i, j) == 1)
		i += j + 2 + 1;
	return (i);
}
