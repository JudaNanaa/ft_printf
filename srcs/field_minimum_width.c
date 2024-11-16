/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_minimum_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:48:18 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 22:45:00 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	field_minimum_width(t_data *data)
{
	char			*dest;
	unsigned int	len_arg;
	unsigned int	len_to_set;

	len_arg = data->format.len;
	if (len_arg >= data->format.min_width)
		return (0);
	len_to_set = data->format.min_width - len_arg;
	dest = ft_calloc(sizeof(char), (data->format.min_width + 1));
	if (dest == NULL)
		return (-1);
	ft_memset(dest, ' ', len_to_set);
	ft_memcpy(dest + len_to_set, data->format.arg, len_arg);
	free(data->format.arg);
	data->format.arg = dest;
	data->format.len = data->format.min_width;
	return (0);
}
