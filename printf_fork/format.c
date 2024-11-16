/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:16:44 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 14:18:41 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdbool.h>

int format_char(t_data *data, char c)
{
	data->format.arg = malloc(sizeof(char) * (1 + 1));
	if (data->format.arg == NULL)
		return (-1);
	data->format.arg[0] = c;
	data->format.arg[1] = '\0';
	data->format.len++;
	return (0);
}

int format_str(t_data *data, char *str)
{
	if (str == NULL)
	{
		data->format.arg = ft_strdup("(null)");
		if (data->format.arg == NULL)
			return (-1);
		data->format.len = 6;
		data->format.nulptr = true;
		return 0;
	}
	data->format.arg = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (data->format.arg == NULL)
		return (-1);
	ft_strcpy(data->format.arg, str);
	data->format.len = ft_strlen(str);
	return (0);
}

int format_int(t_data *data, int nb)
{
	data->format.arg = ft_itoa(nb);
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int format_unsigned(t_data *data, unsigned int nb)
{
	data->format.arg = ft_itoa_base(nb, "0123456789");
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int format_lower_x(t_data *data, unsigned int nb)
{
	data->format.arg = ft_itoa_base(nb, "0123456789abcdef");
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int format_upper_x(t_data *data, unsigned int nb)
{
	data->format.arg = ft_itoa_base(nb, "0123456789ABCDEF");
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}

int format_pointer(t_data *data, unsigned long long nb)
{
	char *pointer;

	if (nb == 0)
	{
		data->format.arg = ft_strdup("(nil)");
		if (data->format.arg == NULL)
			return (-1);
		data->format.len = ft_strlen(data->format.arg);
		return (0);
	}
	pointer = ft_itoa_long_long(nb, "0123456789abcdef");
	if (pointer == NULL)
		return (-1);
	data->format.arg = ft_strjoin("0x", pointer);
	free(pointer);
	if (data->format.arg == NULL)
		return (-1);
	data->format.len = ft_strlen(data->format.arg);
	return (0);
}