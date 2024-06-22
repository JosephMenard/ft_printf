/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:15:56 by joseph            #+#    #+#             */
/*   Updated: 2024/06/22 16:30:16 by joseph           ###   ########.fr       */
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
	else
	{
		len_printf += ft_putchar('%');
		len_printf += ft_putchar(f);
	}
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
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len_printf += ft_choix_format(args, str[i + 1]);
			i++;
		}
		else
			len_printf += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len_printf);
}

// int	main(int ac, char **av)
// {
// 	int		nbr;
// 	char	*str;

// 	(void)ac;
// 	(void)av;
// 	str = " %c %%%9 %c %10 %c %?";
// 	nbr = ft_printf(str, '5', '1', '4');
// 	printf("\n ft ; %d \n", nbr);
// 	nbr = printf(str, '5', '1', '4');
// 	printf("\n rl ; %d \n", nbr);
// 	printf("\n ============================================ \n");
// 	str = " %c %u %d %s %%%x %X %p";
// 	nbr = ft_printf(str, '5', -10, 1, str, 5464, 4654, str);
// 	printf("\n ft ; %d \n", nbr);
// 	nbr = printf(str, '5', -10, 1, str, 5464, 4654, str);
// 	printf("\n rl ; %d \n", nbr);
// 	printf("\n ============================================ \n");
// 	str = " %?%% %";
// 	nbr = ft_printf(str, str);
// 	printf("\n ft ; %d \n", nbr);
// 	nbr = printf(str, str);
// 	printf("\n rl ; %d \n", nbr);
// 	return (0);
// }







