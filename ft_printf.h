/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:05:26 by madamou           #+#    #+#             */
/*   Updated: 2024/04/14 21:01:14 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
int		ft_size_malloc(long nb, int len_base);
int		ft_size_malloc_long(unsigned long long int nb, int len_base);
int		ft_len_print(int cas);
int		ft_check_basic(const char *str, int i);
int		ft_check_bonus(const char *str, int i);
int		ft_check_zero(const char *str, int i, int j);

char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_base(unsigned int nb, char *base);
char	*ft_itoa_long_long(unsigned long long int nb, char *base);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *print, char *src);
char	*ft_realloc(char *print, int len_realloc);
char	*ft_char(char *print, char c);
char	*ft_string(char *print, char *str);
char	*ft_string_space(char *print, char *str, int nb_space);
char	*ft_string_zero(char *print, char *str, int nb_string);
char	*ft_fill_zero1(char *print, int nb_zero, char *result, int sign);
char	*ft_decimal(char *print, int nb, int cas);
char	*ft_decimal_zero(char *print, int nb, int result);
char	*ft_decimal_zero1(char *print, int nb, int nb_zero);
char	*ft_unsigned(char *print, unsigned int nb);
char	*ft_unsigned_zero(char *print, unsigned int nb, int nb_zero);
char	*ft_hexa_lowercase(char *print, unsigned int nb, int cas);
char	*ft_hexa_uppercase(char *print, unsigned int nb, int cas);
char	*ft_hexa_lowercase_zero(char *print, unsigned int nb, int nb_zero);
char	*ft_hexa_uppercase_zero(char *print, unsigned int nb, int nb_zero);
char	*ft_pointer(char *print, void *ptr);
char	*ft_format_if_zero(const char *str, int i, char *print, va_list args);
char	*ft_fill_zero(char *print, int nb_zero, char *result, int sign);
char	*ft_str_to_print(char *print, char c);
char	*ft_string_space1(char *print, char *str, int nb_space);
char	*ft_decimal_zero2(char *print, int nb, int nb_zero);

#endif