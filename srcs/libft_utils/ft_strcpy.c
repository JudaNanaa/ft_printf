/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:06:29 by marvin            #+#    #+#             */
/*   Updated: 2024/11/16 22:33:19 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_strcpy(char *dest, char *src)
{
	size_t	*intdest;
	size_t	*intsrc;
	size_t	len_int;
	size_t	i;

	intdest = (size_t *)dest;
	intsrc = (size_t *)src;
	len_int = ft_strlen(src) / sizeof(size_t);
	i = 0;
	while (i < len_int)
	{
		intdest[i] = intsrc[i];
		i++;
	}
	i *= sizeof(size_t);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest[i] = '\0', dest);
}

/*int main(void)
{
	char test[] = "je vais m'enerver";
	char oui[] = "enfait non01";
	printf("%s\n", ft_strcpy(test, oui));
}*/