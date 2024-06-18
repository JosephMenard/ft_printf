/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:50:34 by joseph            #+#    #+#             */
/*   Updated: 2024/06/18 22:05:55 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<limits.h>

int		ft_printf(const char *str, ...);
int		ft_choix_format(va_list args, const char f);
int		ft_putstr(const char *str);
int		ft_putchar(int c);
int		ft_nbr_len(int n, int fonction);
void	ft_putnbr(int n);
void	ft_putnbr_unsigned(unsigned int n);
int		ft_nbr_len_unsigned(unsigned int n, int fonction);
void	ft_putnbr_base(unsigned long int nbr, const char *base);
int		ft_ptr_len(unsigned long n);
size_t	ft_strlen(const char *str);
void    compare_printfs(int test_num, const char *format, ...);

#endif