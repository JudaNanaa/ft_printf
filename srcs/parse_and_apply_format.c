/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_apply_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:08:06 by madamou           #+#    #+#             */
/*   Updated: 2024/11/17 15:45:13 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_flag_type(char c, t_data *data, va_list args)
{
	if (c == 'c')
		return (format_char(data, (char)va_arg(args, int)));
	if (c == 's')
		return (format_str(data, (char *)va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (format_int(data, (int)va_arg(args, int)));
	if (c == 'u')
		return (format_unsigned(data, (unsigned int)va_arg(args,
					unsigned int)));
	if (c == 'x')
		return (format_lower_x(data, (unsigned int)va_arg(args, unsigned int)));
	if (c == 'X')
		return (format_upper_x(data, (unsigned int)va_arg(args, unsigned int)));
	if (c == 'p')
		return (format_pointer(data, (unsigned long long)va_arg(args, void *)));
	if (c == '%')
		return (format_char(data, '%'));
	return (-1);
}

void	set_min_width_and_precision(t_data *data, char *str)
{
	if (str[0])
		data->format.min_width = ft_atoi(str);
	if (ft_strchr(str, '.') != NULL)
	{
		data->format.options[DOT] = 1;
		data->format.precision = ft_atoi(ft_strchr(str, '.') + 1);
	}
}

void	set_options(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = data->format.format;
	ft_bzero(data->format.options, sizeof(int) * 5);
	while (str[i] && (!ft_isdigit(str[i]) || str[i] == '0') && str[i] != '.')
	{
		if (str[i] == '-')
			data->format.options[MINUS] = 1;
		else if (str[i] == '+')
			data->format.options[PLUS] = 1;
		else if (str[i] == ' ')
			data->format.options[SPACE] = 1;
		else if (str[i] == '0')
			data->format.options[ZERO] = 1;
		else if (str[i] == '#')
			data->format.options[HASH] = 1;
		++i;
	}
	set_min_width_and_precision(data, &str[i]);
}

int	process_flag_to_arg(t_data *data)
{
	if (data->format.options[PLUS] == true && flag_plus(data) == -1)
		return (-1);
	if (data->format.options[SPACE] == true && flag_space(data) == -1)
		return (-1);
	if (data->format.options[HASH] == true && flag_hash(data) == -1)
		return (-1);
	if (data->format.options[DOT] == true)
	{
		if (precision(data) == -1)
			return (-1);
	}
	else if (data->format.options[ZERO] == true && flag_zero(data) == -1)
		return (-1);
	if (data->format.options[MINUS] == true && flag_minus(data) == -1)
		return (-1);
	return (field_minimum_width(data));
}

int	parse_flag(const char *str, t_data *data, va_list args)
{
	int	i;

	i = 0;
	while (str[i] && (!ft_isalpha(str[i]) && str[i] != '%'))
	{
		data->format.format[i] = str[i];
		++i;
	}
	data->format.format[i] = '\0';
	data->format.flag = str[i];
	if (check_flag_type(str[i], data, args) == -1)
		return (-1);
	set_options(data);
	if (str[i] != '%')
	{
		if (process_flag_to_arg(data) == -1)
			return (free(data->format.arg), -1);
	}
	add_arg_to_buffer(data);
	ft_bzero(&data->format, sizeof(data->format));
	return (++i);
}
