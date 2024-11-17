/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:34:44 by madamou           #+#    #+#             */
/*   Updated: 2024/11/17 15:24:12 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	clear_arg(t_data *data)
{
	free(data->format.arg);
	data->format.arg = ft_strnew(0);
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = 0;
	return (0);
}

int	precision_decimal(t_data *data)
{
	char			*dest;
	unsigned int	len_arg;
	int				sign;

	sign = 0;
	len_arg = data->format.len;
	if (data->format.precision == 0 && ft_atoi(data->format.arg) == 0)
		return (clear_arg(data));
	if (len_arg > data->format.precision)
		return (0);
	dest = ft_calloc(sizeof(char), (data->format.precision + 3));
	if (dest == NULL)
		return (-1);
	if (data->format.arg[0] == '-' || data->format.arg[0] == '+')
	{
		dest[0] = data->format.arg[0];
		sign = 1;
	}
	ft_memset(dest + sign, '0', data->format.precision - len_arg + sign);
	ft_strcat(dest, data->format.arg + sign);
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int	precision_unsigned_hexa(t_data *data)
{
	char			*dest;
	unsigned int	len_arg;

	len_arg = data->format.len;
	if (data->format.precision == 0 && ft_atoi_base(data->format.arg, 16) == 0)
		return (clear_arg(data));
	if (len_arg > data->format.precision)
		return (0);
	dest = ft_calloc(sizeof(char), (data->format.precision + 2));
	if (dest == NULL)
		return (-1);
	ft_memset(dest, '0', data->format.precision - len_arg);
	ft_strcat(dest, data->format.arg);
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int	precision(t_data *data)
{
	char			*dest;
	unsigned int	len_arg;

	len_arg = data->format.len;
	if (data->format.flag == 'c')
		return (0);
	if (data->format.flag == 's' && data->format.nulptr == true
		&& len_arg > data->format.precision)
		return (clear_arg(data));
	if (data->format.flag == 'd' || data->format.flag == 'i')
		return (precision_decimal(data));
	if (data->format.flag == 'u' || data->format.flag == 'x'
		|| data->format.flag == 'X')
		return (precision_unsigned_hexa(data));
	if (len_arg <= data->format.precision)
		return (0);
	dest = ft_calloc(sizeof(char), (data->format.precision + 2));
	if (dest == NULL)
		return (-1);
	ft_memcpy(dest, data->format.arg, data->format.precision);
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}
