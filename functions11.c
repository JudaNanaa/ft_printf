/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions11.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:21:15 by madamou           #+#    #+#             */
/*   Updated: 2024/04/20 11:25:50 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat(char *print, char *src)
{
	size_t	i;
	size_t	j;

	i = ft_len_print(2);
	j = 0;
	while (src[j])
	{
		print[i++] = src[j++];
		ft_len_print(1);
	}
	print[i] = '\0';
	return (print);
}

int	ft_check_basic(const char *str, int i)
{
	if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
			|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
			|| str[i + 1] == 'p'))
		return (1);
	return (0);
}

int	ft_check_bonus(const char *str, int i)
{
	if (str[i] == '%' && (str[i + 1] == '0' || str[i + 1] == '.'
			|| str[i + 1] == ' ' || str[i + 1] == '-' || (str[i + 1] >= '1'
				&& str[i + 1] <= '9') || str[i + 1] == '#'
			|| str[i + 1] == ' ' || str[i + 1] == '+'))
		return (1);
	return (0);
}

int	ft_nb_zero(const char *str, int i)
{
	int	nb_zero;
	int	j;

	j = 0;
	nb_zero = 0;
	if (str[i + 1] >= '1' && str[i + 1] <= '9')
		nb_zero = str[i + j + 1] - '0';
	while (str[i + j + 2] >= '0' && str[i + j + 2] <= '9')
		nb_zero = (nb_zero * 10) + (str[i + j++ + 2] - '0');
	return (nb_zero);
}

int	ft_increment(const char *str, int i)
{
	int	nb_zero;
	int	j;

	j = 0;
	nb_zero = 0;
	if (str[i + 1] >= '1' && str[i + 1] <= '9')
		nb_zero = str[i + j + 1] - '0';
	while (str[i + j + 2] >= '0' && str[i + j + 2] <= '9')
		nb_zero = (nb_zero * 10) + (str[i + j++ + 2] - '0');
	return (j);
}
