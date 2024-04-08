/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:03:40 by madamou           #+#    #+#             */
/*   Updated: 2024/04/06 16:13:45 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
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

	i = ft_strlen(print);
	tmp = malloc(sizeof(char) * (ft_strlen(print) + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	tmp = ft_strcpy(tmp, print);
	free(print);
	print = malloc(sizeof(char) * (ft_strlen(tmp) + 1 + 1));
	if (!print)
		return (free(tmp), NULL);
	print = ft_strcpy(print, tmp);
	print[i++] = c;
	print[i] = '\0';
	return (free(tmp), print);
}

char	*ft_char(char *print, int c)
{
	print = ft_realloc(print, 1);
	if (!print)
		return (NULL);
	print = ft_strcat(print, (char *)&c);
	return (print);
}

char	*ft_decimal(char *print, int nb)
{
	char	*result;
	int		len_result;

	result = ft_itoa(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	print = ft_realloc(print, len_result);
	if (!print)
		return (NULL);
	print = ft_strcat(print, result);
	return (free(result), print);
}
