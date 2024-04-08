/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:08:52 by madamou           #+#    #+#             */
/*   Updated: 2024/04/08 19:57:19 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../Includes/ft_printf.h"

// int	main(void)
// {
// 	int ret1, ret2;

// 	// Test 1
// 	ret1 = printf("Original printf: %s\n", "Hello, world!");
// 	ret2 = ft_printf("Custom printf: %s\n", "Hello, world!");
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 2
// 	ret1 = printf("Original printf: %d\n", 42);
// 	ret2 = ft_printf("Custom printf: %d\n", 42);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 3
// 	ret1 = printf("Original printf: %.2f\n", 3.14159);
// 	ret2 = ft_printf("Custom printf: %.2f\n", 3.14159);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 4
// 	ret1 = printf("Original printf: %c\n", 'A');
// 	ret2 = ft_printf("Custom printf: %c\n", 'A');
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 5
// 	ret1 = printf("Original printf: %p\n", (void *)0x12345678);
// 	ret2 = ft_printf("Custom printf: %p\n", (void *)0x12345678);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 6
// 	char *str = "Test string";
// 	ret1 = printf("Original printf: %s\n", str);
// 	ret2 = ft_printf("Custom printf: %s\n", str);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 7
// 	int num = 12345;
// 	ret1 = printf("Original printf: %i\n", num);
// 	ret2 = ft_printf("Custom printf: %i\n", num);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 8
// 	ret1 = printf("Original printf: %u\n", 12345);
// 	ret2 = ft_printf("Custom printf: %u\n", 12345);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 9
// 	ret1 = printf("Original printf: %x\n", 255);
// 	ret2 = ft_printf("Custom printf: %x\n", 255);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 10
// 	ret1 = printf("Original printf: %X\n", 255);
// 	ret2 = ft_printf("Custom printf: %X\n", 255);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 11
// 	ret1 = printf("Original printf: %%\n");
// 	ret2 = ft_printf("Custom printf: %%\n");
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 12
// 	ret1 = printf("Original printf: %c\n", 65);
// 	ret2 = ft_printf("Custom printf: %c\n", 65);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 13
// 	ret1 = printf("Original printf: %010d\n", 123);
// 	ret2 = ft_printf("Custom printf: %010d\n", 123);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 14
// 	ret1 = printf("Original printf: %-10s\n", "hello");
// 	ret2 = ft_printf("Custom printf: %-10s\n", "hello");
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 15
// 	ret1 = printf("Original printf: %.*s\n", 3, "world");
// 	ret2 = ft_printf("Custom printf: %.*s\n", 3, "world");
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 16
// 	ret1 = printf("Original printf: %10.5f\n", 123.456);
// 	ret2 = ft_printf("Custom printf: %10.5f\n", 123.456);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 17
// 	ret1 = printf("Original printf: %010.2f\n", 123.456);
// 	ret2 = ft_printf("Custom printf: %010.2f\n", 123.456);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 18
// 	ret1 = printf("Original printf: %0-10d\n", 123);
// 	ret2 = ft_printf("Custom printf: %0-10d\n", 123);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 19
// 	ret1 = printf("Original printf: %*.*f\n", 8, 3, 123.456);
// 	ret2 = ft_printf("Custom printf: %*.*f\n", 8, 3, 123.456);
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");

// 	// Test 20
// 	ret1 = printf("Original printf: %10.2s\n", "test");
// 	ret2 = ft_printf("Custom printf: %10.2s\n", "test");
// 	printf("Return value of original printf: %d\n", ret1);
// 	printf("Return value of custom printf: %d\n", ret2 + 2);
// 	printf("\n");
// }