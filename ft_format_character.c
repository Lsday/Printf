/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:49:41 by oronda            #+#    #+#             */
/*   Updated: 2021/10/27 10:17:20 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_format_character(va_list lst)
{
	char	c;

	c = (char)(va_arg(lst, int));
	ft_putchar_fd(c, 1);
	return (1);
}
