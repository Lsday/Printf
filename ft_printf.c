/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:26:21 by oronda            #+#    #+#             */
/*   Updated: 2021/10/23 16:26:21 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	compute(const char *input, va_list args, int (*test[])(va_list))
{
	int	sum;

	sum = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 'c' || *input == 's' || *input == 'p' || *input == 'd'
				|| *input == 'i' || *input == 'u' || *input == 'x'
				|| *input == 'X' || *input == '%')
			{
				sum += test[(int) *input++](args);
			}
		}
		else
		{
			ft_putchar_fd(*input++, 1);
			sum++;
		}
	}
	return (sum);
}

void	init(int (*test[256])(va_list))
{
	test['c'] = ft_format_character;
	test['s'] = ft_format_string;
	test['p'] = ft_format_pointer;
	test['d'] = ft_format_decimal;
	test['i'] = ft_format_decimal;
	test['u'] = ft_format_unsigned_decimal;
	test['x'] = ft_format_lower_hex;
	test['X'] = ft_format_upper_hex;
	test['%'] = ft_format_percent;
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		sum;
	int		(*test[256])(va_list);

	va_start(args, input);
	init(test);
	sum = compute(input, args, test);
	va_end(args);
	return (sum);
}
