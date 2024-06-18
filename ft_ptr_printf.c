/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:57:39 by jmenard           #+#    #+#             */
/*   Updated: 2024/06/03 14:35:15 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long n)
{
	int		i;

	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = 2;
	ft_putnbr_base(n, "0123456789abcdef");
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
