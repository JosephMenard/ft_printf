/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:33:30 by jmenard           #+#    #+#             */
/*   Updated: 2024/06/15 19:42:12 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(int n, int fonction)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	if (fonction == 1)
		ft_putnbr(n);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_nbr_len_unsigned(unsigned int n, int fonction)
{
	int					i;
	int					base;
	unsigned long int	nb;

	i = 0;
	base = 10;
	nb = (unsigned long int)n;
	if (n == 0)
		i++;
	if (fonction == 1)
		ft_putnbr_unsigned(nb);
	else if (fonction >= 2)
	{
		if (fonction == 2)
			ft_putnbr_base(n, "0123456789abcdef");
		else if (fonction == 3)
			ft_putnbr_base(n, "0123456789ABCDEF");
		base = 16;
	}
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	int			nb;

	if (n <= -2147483647)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	nb = n % 10;
	n = n / 10;
	if (n != 0)
		ft_putnbr(n);
	nb += 48;
	write(1, &nb, 1);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	int			nb;

	nb = n % 10;
	n = n / 10;
	if (n != 0)
		ft_putnbr(n);
	nb += 48;
	write(1, &nb, 1);
}
