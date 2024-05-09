/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:03:40 by madamou           #+#    #+#             */
/*   Updated: 2024/05/09 00:46:38 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strcpyy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (i < ft_len_print(2))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_str_to_print(char *print, char c)
{
	char	*tmp;
	int		i;

	i = ft_len_print(2);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	tmp = ft_strcpyy(tmp, print);
	free(print);
	print = malloc(sizeof(char) * (i + 1 + 1));
	if (!print)
		return (free(tmp), NULL);
	print = ft_strcpyy(print, tmp);
	print[i] = c;
	ft_len_print(1);
	print[++i] = '\0';
	return (free(tmp), print);
}

char	*ft_char(char *print, char c)
{
	int	i;

	i = ft_len_print(2);
	print = ft_reallocc(print, 3);
	if (!print)
		return (NULL);
	print[i] = c;
	ft_len_print(1);
	print[++i] = '\0';
	return (print);
}

char	*ft_decimal(char *print, int nb, int cas)
{
	char	*result;
	int		len_result;

	result = ft_itoa(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen1(result);
	if ((cas == 2 || cas == 3) && nb >= 0)
		len_result++;
	print = ft_reallocc(print, len_result);
	if (!print)
		return (NULL);
	if (cas == 2 && nb >= 0)
		print = ft_strcatt(print, " ");
	if (cas == 3 && nb >= 0)
		print = ft_strcatt(print, "+");
	print = ft_strcatt(print, result);
	return (free(result), print);
}
