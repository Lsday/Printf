/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_lower_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:04:28 by oronda            #+#    #+#             */
/*   Updated: 2021/10/27 10:18:06 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_format_lower_hex(va_list arg)
{
	int				sum;
	int				i;
	char			*hex;
	char			p[16];
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	hex = "0123456789abcdef";
	sum = 0;
	if (!nb)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0 ;
	while (nb)
	{
		p[i++] = hex[nb % 16];
		nb /= 16;
	}
	sum += i;
	while (i)
		ft_putchar_fd(p[--i], 1);
	return (sum);
}
