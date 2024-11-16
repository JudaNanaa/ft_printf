/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:05:26 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 22:42:50 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "utils.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_BUFFER 1024

typedef enum s_options
{
	MINUS,
	PLUS,
	ZERO,
	SPACE,
	HASH,
	DOT,
}					t_options;

typedef struct s_format
{
	char			format[100];
	char			*arg;
	unsigned int	len;
	char			flag;
	unsigned int	min_width;
	unsigned int	precision;
	bool			nulptr;
	int				options[6];
}					t_format;

typedef struct s_data
{
	char			buffer[MAX_BUFFER];
	t_format		format;
	unsigned int	len;
	unsigned int	nb_print;
}					t_data;

int					ft_printf(const char *str, ...);

// Parsing
int					parse_flag(const char *str, t_data *data, va_list args);

// Format
int					format_char(t_data *print, char c);
int					format_str(t_data *data, char *str);
int					format_int(t_data *data, int nb);
int					format_unsigned(t_data *data, unsigned int nb);
int					format_lower_x(t_data *data, unsigned int nb);
int					format_upper_x(t_data *data, unsigned int nb);
int					format_pointer(t_data *data, unsigned long long nb);

// Utils
char				*ft_itoa_base(unsigned int nb, char *base);
char				*ft_itoa_long_long(unsigned long long int nb, char *base);
int					ft_atoi_base(const char *str, int str_base);

// Flags
int					flag_plus(t_data *data);
int					flag_space(t_data *data);
int					flag_hash(t_data *data);
int					flag_minus(t_data *data);
int					flag_zero(t_data *data);
int					field_minimum_width(t_data *data);
int					precision(t_data *data);

// Buffer functions
int					add_arg_to_buffer(t_data *data);
int					add_char_to_buffer(t_data *data, char c);
void				print_buffer(t_data *data);

#endif