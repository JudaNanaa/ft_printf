/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:04:51 by madamou           #+#    #+#             */
/*   Updated: 2024/11/16 22:24:49 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned long	i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = c;
	return (s);
}

/*int	main(void)
{
	char imad[] = "oui je test";
	printf("%s\n", (imad));
	printf("%p\n", memset(imad, 'A', 10));
	printf("%s\n", (imad));
	char imad1[] = "oui je test";
	printf("%s\n", (imad1));
	printf("%p\n", ft_memset(imad1, 'A', 10));
	printf("%s\n", (imad1));
}*/