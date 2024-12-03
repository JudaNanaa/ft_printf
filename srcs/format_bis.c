/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:49:55 by madamou           #+#    #+#             */
/*   Updated: 2024/12/03 01:11:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_unsigned(t_printf *data, unsigned int nb)
{
	data->format.arg = ft_itoa_base(nb, "0123456789");
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int	format_lower_x(t_printf *data, unsigned int nb)
{
	data->format.arg = ft_itoa_base(nb, "0123456789abcdef");
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int	format_upper_x(t_printf *data, unsigned int nb)
{
	data->format.arg = ft_itoa_base(nb, "0123456789ABCDEF");
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}
