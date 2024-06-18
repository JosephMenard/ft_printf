/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:15:56 by joseph            #+#    #+#             */
/*   Updated: 2024/06/18 22:10:48 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choix_format(va_list args, const char f)
{
	int	len_printf;

	len_printf = 0;
	if (f == 'c')
		len_printf += ft_putchar(va_arg(args, int));
	else if (f == 's')
		len_printf += ft_putstr(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		len_printf += ft_nbr_len(va_arg(args, int), 1);
	else if (f == 'u')
		len_printf += ft_nbr_len_unsigned(va_arg(args, unsigned int), 1);
	else if (f == '%')
		len_printf += ft_putchar('%');
	else if (f == 'x')
		len_printf += ft_nbr_len_unsigned(va_arg(args, unsigned int), 2);
	else if (f == 'X')
		len_printf += ft_nbr_len_unsigned(va_arg(args, unsigned int), 3);
	else if (f == 'p')
		len_printf += ft_ptr_len(va_arg(args, unsigned long));
	return (len_printf);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len_printf;

	i = 0;
	len_printf = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				len_printf += ft_putchar(va_arg(args, int));
			else if (str[i + 1] == 's')
				len_printf += ft_putstr(va_arg(args, char *));
			else if (str[i + 1] == 'd' || str[i] == 'i')
				len_printf += ft_nbr_len(va_arg(args, int), 1);
			else if (str[i + 1] == 'u')
				len_printf += ft_nbr_len_unsigned(va_arg(args, unsigned int), 1);
			else if (str[i + 1] == '%')
				len_printf += ft_putchar('%');
			else if (str[i + 1] == 'x')
				len_printf += ft_nbr_len_unsigned(va_arg(args, unsigned int), 2);
			else if (str[i + 1] == 'X')
				len_printf += ft_nbr_len_unsigned(va_arg(args, unsigned int), 3);
			else if (str[i + 1] == 'p')
				len_printf += ft_ptr_len(va_arg(args, unsigned long));
			i++;
		}
		else
			len_printf += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len_printf);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h> // Pour ptrdiff_t

#include "ft_printf.h"

#define BUFFER_SIZE 1024

void compare_printfs(int test_num, const char *format, ...)
{
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    int ret1, ret2;

    va_list args1, args2;

    // Capture output of printf
    va_start(args1, format);
    FILE *fp1 = fmemopen(buffer1, BUFFER_SIZE, "w");
    if (fp1 == NULL) {
        perror("fmemopen");
        exit(EXIT_FAILURE);
    }
    ret1 = vfprintf(fp1, format, args1);
    va_end(args1);
    fclose(fp1);

    // Capture output of ft_printf
    va_start(args2, format);
    FILE *fp2 = fmemopen(buffer2, BUFFER_SIZE, "w");
    if (fp2 == NULL) {
        perror("fmemopen");
        exit(EXIT_FAILURE);
    }
    ret2 = vfprintf(fp2, format, args2); // Remplacez par vft_printf si disponible
    va_end(args2);
    fclose(fp2);

    // Compare outputs
    if (ret1 == ret2 && strcmp(buffer1, buffer2) == 0)
        printf("Test %d: OK\n", test_num);
    else
        printf("Test %d: KO\n", test_num);
}

int main()
{
    // char *str = NULL;
    // int *ptr = NULL;

    // Basic tests
    // compare_printfs(1, "Test 1: Char: %c, String: %s, Int: %d\n", 'A', "Hello", 123);
    // compare_printfs(2, "Test 2: Signed: %d, Unsigned: %u\n", -123, 123);
    // compare_printfs(3, "Test 3: Hex (lowercase): %x, Hex (uppercase): %X\n", 255, 255);
    // compare_printfs(4, "Test 4: Percentage: %%, Char: %c\n", 'B');
    // compare_printfs(5, "Test 5: Pointer: %p\n", &ptr);
    // compare_printfs(6, "Test 6: %c %s %d %u %x %X %%\n", 'C', "Complex", -456, 456, 0xabc, 0xABC);
    // compare_printfs(7, "Test 7: Null string: %s\n", str);
    // compare_printfs(8, "Test 8: %c %s %d %u %x %X %p %%\n", 'D', "DataMix", -789, 789, 0xdef, 0xDEF, &ptr);
    // compare_printfs(9, "Test 9: Long string: %s\n", "This is a very long string used for testing the custom printf implementation.");
    // compare_printfs(10, "Test 10: Large number: %d\n", 2147483647);
    // compare_printfs(11, "Test 11: Zero: %d, Negative: %d, Max Unsigned: %u\n", 0, -2147483648, 4294967295U);
    // compare_printfs(12, "Test 12: Null pointer: %p\n", NULL);
    // compare_printfs(13, "Test 13: Negative hex (unsigned): %x\n", -1);
    // compare_printfs(14, "Test 14: %c %s %d %u %x %X %p %% %s %d\n", 'E', "Everything", -1234, 1234, 0xbeef, 0xBEEF, &ptr, "Extra", 42);

    // // Advanced tests
    // compare_printfs(15, "Test 15: Multiple consecutive format specifiers: %d%d%d%d%d\n", 1, 2, 3, 4, 5);
    // compare_printfs(16, "Test 16: Width and precision: %10.5d, %10.5s\n", 123, "Hello");
    // compare_printfs(17, "Test 17: Left-justified: %-10d, %-10s\n", 123, "Left");
    // compare_printfs(18, "Test 18: Zero-padded: %010d, %010s\n", 123, "Zero");
    // compare_printfs(19, "Test 19: Space and plus sign: % d, %+d\n", 123, 123);
    // compare_printfs(20, "Test 20: Large width: %100d\n", 123);
    // compare_printfs(21, "Test 21: Large number: %llu\n", 18446744073709551615ULL);
    // compare_printfs(22, "Test 22: Large hex: %llx\n", 18446744073709551615ULL);
    // compare_printfs(23, "Test 23: Multiple types: %c %s %d %u %x %X %p %%\n", 'F', "Mix", -1234, 1234, 0xdeadbeef, 0xDEADBEEF, &ptr);
    // compare_printfs(24, "Test 24: Edge case: %d, %i, %o, %u, %x, %X\n", 0, 0, 0, 0, 0, 0);
    // compare_printfs(25, "Test 25: Mixed flags: %#x, %#o, %+d, % d, %010d\n", 255, 255, 123, 123, 123);
    // compare_printfs(26, "Test 26: Null characters: %c, %c, %c\n", '\0', 'A', '\0');
    // compare_printfs(27, "Test 27: Strings with special characters: %s\n", "Hello\nWorld\t!");
    // compare_printfs(28, "Test 28: Precision with strings: %.5s, %.10s\n", "HelloWorld", "Hello");

    // Additional extreme cases
    // compare_printfs(29, "Test 29: Very large width: %1000d\n", 42);
    // compare_printfs(30, "Test 30: Very large precision: %1000.1000d\n", 42);
	printf("Test rl_29: Very large width: %1000d\n", 42);
	ft_printf("Test ft_29: Very large width: %1000d\n", 42);
	printf("Test rl_30: Very large precision: %1000.1000d\n", 42);
	ft_printf("Test ft_30: Very large precision: %1000.1000d\n", 42);
    // compare_printfs(31, "Test 31: Long double: %Lf\n", 3.141592653589793238L);
    // compare_printfs(32, "Test 32: Mixed specifiers in complex format: %d %s %p %x %% %X %u %c\n", -1234, "Test", &ptr, 0xbeef, 0xBEEF, 1234567890, 'Z');
    // compare_printfs(33, "Test 33: Different bases: %o, %u, %x, %X\n", 123, 123, 123, 123);
    // compare_printfs(34, "Test 34: Large negative numbers: %d, %i\n", -2147483648, -2147483648);
    // compare_printfs(35, "Test 35: Mixing length modifiers: %hhd, %hd, %ld, %lld, %zd, %td\n", (signed char)127, (short)32767, (long)2147483647, (long long)9223372036854775807, (size_t)12345, (ptrdiff_t)12345);

    return 0;
}







