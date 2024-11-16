/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:56:52 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 17:15:53 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdbool.h>

int flag_plus(t_data *data)
{
	char *dest;

	if (data->format.arg[0] != '-' && data->format.arg[0] != '+')
	{
		dest = malloc(sizeof(char) * (data->format.len + 2));
		if (dest == NULL)
			return (-1);
		dest[0] = '+';
		ft_strcpy(&dest[1], data->format.arg);
		free(data->format.arg);
		data->format.arg = dest;
		data->format.len = ft_strlen(data->format.arg);
	}
	return (0);
}

int flag_space(t_data *data)
{
	char *dest;

	if (data->format.flag == 's')
		return (0);
	if (data->format.arg[0] != '-' && data->format.arg[0] != '+')
	{
		dest = malloc(sizeof(char) * (data->format.len + 2));
		if (dest == NULL)
			return (-1);
		dest[0] = ' ';
		ft_strcpy(&dest[1], data->format.arg);
		free(data->format.arg);
		data->format.arg = dest;
		data->format.len = ft_strlen(data->format.arg);
	}
	return (0);
}

int flag_hash(t_data *data)
{
	char *dest;

	if (ft_atoi_base(data->format.arg, 16) == 0)
		return (0);
	dest = malloc(sizeof(char) * (data->format.len + 3));
	if (dest == NULL)
		return (-1);
	if (data->format.flag == 'x')
		ft_strcpy(dest, "0x");
	else if (data->format.flag == 'X')
		ft_strcpy(dest, "0X");
	ft_strcat(dest, data->format.arg);
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int flag_zero(t_data *data)
{
	char *dest;
	unsigned int len_arg;
	
	len_arg = data->format.len;
	if (len_arg >= data->format.min_width)
		return 0;
	dest = ft_calloc(sizeof(char), (data->format.min_width + 1));
	if (dest == NULL)
		return (-1);
	if (data->format.arg[0] == '-' || data->format.arg[0] == '+')
	{
		dest[0] = data->format.arg[0];
		ft_memset(dest + 1, '0', data->format.min_width - len_arg);
		ft_strcat(dest, data->format.arg + 1);
	}
	else
	{
		ft_memset(dest, '0', data->format.min_width - len_arg);
		ft_strcat(dest, data->format.arg);
	}
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int flag_minus(t_data *data)
{
	char *dest;
	unsigned int len_arg;
	
	len_arg = data->format.len;
	if (len_arg >= data->format.min_width)
		return 0;
	dest = ft_calloc(sizeof(char), (data->format.min_width + 1));
	if (dest == NULL)
		return (-1);
	ft_memcpy(dest, data->format.arg, len_arg);
	ft_memset(&dest[len_arg], ' ', data->format.min_width - len_arg);
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = data->format.min_width;
	return (0);
}

int field_minimum_width(t_data *data)
{
	char *dest;
	unsigned int len_arg;

	len_arg = data->format.len;
	if (len_arg >= data->format.min_width)
		return 0;
	dest = ft_calloc(sizeof(char), (data->format.min_width + 1));
	if (dest == NULL)
		return (-1);
	ft_memset(dest, ' ', data->format.min_width - len_arg);
	ft_memcpy(dest + data->format.min_width - len_arg, data->format.arg, len_arg);
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = data->format.min_width;
	return (0);
}

int precision(t_data *data)
{
	char *dest;
	unsigned int len_arg;
	
	len_arg = data->format.len;
	if (data->format.flag == 'c')
		return (0);
	if (data->format.flag == 's' && data->format.nulptr == true && len_arg > data->format.precision)
	{
		free(data->format.arg);
		data->format.arg = ft_strnew(0);
		data->format.len = ft_strlen(data->format.arg);
		return (0);
	}
	if (data->format.flag == 'd' || data->format.flag == 'i')
	{
		if (data->format.precision == 0 && ft_atoi(data->format.arg) == 0)
		{
			free(data->format.arg);
			data->format.arg = ft_strnew(0);
			data->format.len = ft_strlen(data->format.arg);
			return 0;
		}
		if (len_arg > data->format.precision)
			return 0;
		dest = ft_calloc(sizeof(char), (data->format.precision + 3));
		if (dest == NULL)
			return (-1);
		if (data->format.arg[0] == '-' || data->format.arg[0] == '+')
		{
			dest[0] = data->format.arg[0];
			ft_memset(dest + 1, '0', data->format.precision - len_arg + 1);
			ft_strcat(dest, data->format.arg + 1);
		}
		else
		{
			ft_memset(dest, '0', data->format.precision - len_arg);
			ft_strcat(dest, data->format.arg);
		}
		free(data->format.arg);
		data->format.arg = dest;
		data->format.len = ft_strlen(data->format.arg);
		return (0);
	}
	if (data->format.flag == 'u' || data->format.flag == 'x' || data->format.flag == 'X')
	{
		if (data->format.precision == 0 && ft_atoi_base(data->format.arg, 16) == 0)
		{
			free(data->format.arg);
			data->format.arg = ft_strnew(0);
			data->format.len = ft_strlen(data->format.arg);
			return 0;
		}
		if (len_arg > data->format.precision)
			return 0;
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
