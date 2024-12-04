/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:56:52 by madamou           #+#    #+#             */
/*   Updated: 2024/12/04 21:48:14 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdbool.h>

int	flag_plus(t_printf *data)
{
	char	*dest;

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

int	flag_space(t_printf *data)
{
	char	*dest;

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

int	flag_hash(t_printf *data)
{
	char	*dest;

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

int	flag_zero(t_printf *data)
{
	char			*dest;
	unsigned int	len_arg;

	len_arg = data->format.len;
	if (len_arg >= data->format.min_width || data->format.options[DOT]
		|| data->format.options[HASH])
		return (0);
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

int	flag_minus(t_printf *data)
{
	char			*dest;
	unsigned int	len_arg;

	len_arg = data->format.len;
	if (len_arg >= data->format.min_width)
		return (0);
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
