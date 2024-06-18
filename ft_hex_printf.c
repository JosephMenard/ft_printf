/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:58:34 by joseph            #+#    #+#             */
/*   Updated: 2024/06/03 13:42:11 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long int nbr, const char *base)
{
	int	base_len;
	int	c;

	base_len = 16;
	c = nbr % base_len;
	nbr = nbr / base_len;
	if (nbr != 0)
		ft_putnbr_base(nbr, base);
	write(1, &base[c], 1);
}
