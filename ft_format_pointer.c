/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:44:53 by oronda            #+#    #+#             */
/*   Updated: 2021/10/26 18:30:16 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_format_pointer(va_list arg)
{
	int				sum;
	uintptr_t		ptr_tmp;
	int				i;
	char			*hex;
	char			p[16];

	ptr_tmp = (uintptr_t)(va_arg(arg, void *));
	hex = "0123456789abcdef";
	sum = 2;
	ft_putstr_fd("0x", 1);
	if (!ptr_tmp)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	i = 0 ;
	while (ptr_tmp)
	{
		p[i++] = hex[ptr_tmp % 16];
		ptr_tmp /= 16;
	}
	sum += i;
	while (i)
		ft_putchar_fd(p[--i], 1);
	return (sum);
}
