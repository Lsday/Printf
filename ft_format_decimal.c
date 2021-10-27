/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:20:16 by oronda            #+#    #+#             */
/*   Updated: 2021/10/26 18:33:58 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_format_decimal(va_list arg)
{
	int		sum;
	char	*str;

	sum = 0;
	str = ft_itoa(va_arg(arg, int));
	sum = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (sum);
}
