/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../includes/ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:05:26 by madamou           #+#    #+#             */
/*   Updated: 2024/12/03 01:10:48 by madamou          ###   ########.fr       */
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
	char			*str;
	int				fd;
	bool			print;
	t_format		format;
	unsigned int	len;
	unsigned int	nb_print;
}					t_printf;

// Function
int					ft_printf(const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
char				*ft_sprintf(const char *str, ...);
// Parsing
int					parse_flag(const char *str, t_printf *data, va_list args);

// Format
int					format_char(t_printf *print, char c);
int					format_str(t_printf *data, char *str);
int					format_int(t_printf *data, int nb);
int					format_unsigned(t_printf *data, unsigned int nb);
int					format_lower_x(t_printf *data, unsigned int nb);
int					format_upper_x(t_printf *data, unsigned int nb);
int					format_pointer(t_printf *data, unsigned long long nb);

// Utils
char				*ft_itoa_base(unsigned int nb, char *base);
char				*ft_itoa_long_long(unsigned long long int nb, char *base);
int					ft_atoi_base(const char *str, int str_base);

// Flags
int					flag_plus(t_printf *data);
int					flag_space(t_printf *data);
int					flag_hash(t_printf *data);
int					flag_minus(t_printf *data);
int					flag_zero(t_printf *data);
int					field_minimum_width(t_printf *data);
int					precision(t_printf *data);

// Buffer functions
int					add_arg_to_buffer(t_printf *data);
int					add_char_to_buffer(t_printf *data, char c);
int					print_buffer(t_printf *data);
int					concatenate_str(t_printf *data);
void				flush_buffer(t_printf *data);
#endif