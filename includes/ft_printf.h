/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:26:59 by oronda            #+#    #+#             */
/*   Updated: 2021/10/23 16:26:59 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_format_string(va_list lst);
int	ft_format_character(va_list lst);
int	ft_format_pointer(va_list lst);
int	ft_format_decimal(va_list lst);
int	ft_format_unsigned_decimal(va_list lst);
int	ft_format_lower_hex(va_list lst);
int	ft_format_upper_hex(va_list lst);
int	ft_format_percent(va_list lst);

#endif