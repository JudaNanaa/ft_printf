/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:03:29 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 22:22:24 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_buffer(t_data *data)
{
	data->nb_print += write(STDOUT_FILENO, data->buffer, data->len);
}

int	add_char_to_buffer(t_data *data, char c)
{
	data->buffer[data->len] = c;
	data->len++;
	if (data->len == MAX_BUFFER)
	{
		print_buffer(data);
		data->len = 0;
		ft_bzero(data->buffer, sizeof(char) * MAX_BUFFER);
	}
	return (0);
}

int	add_arg_to_buffer(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->format.len)
	{
		add_char_to_buffer(data, data->format.arg[i]);
		++i;
	}
	free(data->format.arg);
	return (0);
}
