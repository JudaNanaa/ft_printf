/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:03:29 by madamou           #+#    #+#             */
/*   Updated: 2024/12/03 01:11:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flush_buffer(t_printf *data)
{
	if (data->print == true)
	{
		if (print_buffer(data) == -1)
			data->nb_print = -1;
	}
	else
	{
		if (concatenate_str(data) == -1)
			data->str = NULL;
	}
}

int	print_buffer(t_printf *data)
{
	int	n;

	n = write(data->fd, data->buffer, data->len);
	if (n == -1)
		return (-1);
	data->nb_print += n;
	return (0);
}

int	concatenate_str(t_printf *data)
{
	char	*dest;

	if (data->str == NULL)
	{
		data->str = malloc(sizeof(char) * (data->len + 1));
		if (data->str == NULL)
			return (-1);
	}
	else
	{
		dest = malloc(sizeof(char) * (data->nb_print + data->len + 1));
		if (dest == NULL)
			return (free(data->str), -1);
		ft_memcpy(dest, data->str, data->nb_print);
		free(data->str);
		data->str = dest;
	}
	ft_memcpy(&data->str[data->nb_print], data->buffer, data->len);
	data->str[data->len] = '\0';
	data->nb_print += data->len;
	return (0);
}

int	add_char_to_buffer(t_printf *data, char c)
{
	int	result;

	data->buffer[data->len] = c;
	data->len++;
	if (data->len == MAX_BUFFER)
	{
		if (data->print == true)
			result = print_buffer(data);
		else
			result = concatenate_str(data);
		if (result == -1)
			return (-1);
		data->len = 0;
		ft_bzero(data->buffer, sizeof(char) * MAX_BUFFER);
	}
	return (0);
}

int	add_arg_to_buffer(t_printf *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->format.len)
	{
		if (add_char_to_buffer(data, data->format.arg[i]) == -1)
			return (free(data->format.arg), -1);
		++i;
	}
	free(data->format.arg);
	return (0);
}
