/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned_decimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:12:53 by oronda            #+#    #+#             */
/*   Updated: 2021/10/27 10:16:52 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static char	*zero(char *result)
{
	result = malloc(2);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static char	*positive(char *result, int digits, unsigned int unb)
{
	result = malloc(sizeof(char) * digits + 1);
	if (!result)
		return (NULL);
	result[digits] = '\0';
	while (digits)
	{
		result[digits - 1] = (unb % 10) + '0';
		unb /= 10;
		digits--;
	}
	return (result);
}

static int	digits_count(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_utoa(unsigned int unb)
{
	int				signe;
	char			*result;
	int				digits;

	result = NULL;
	signe = 1;
	digits = digits_count(unb);
	if (unb == 0)
		result = zero(result);
	else if (signe > 0)
		result = positive(result, digits, unb);
	return (result);
}

int	ft_format_unsigned_decimal(va_list arg)
{
	unsigned int	sum;
	unsigned int	unb;
	char			*str;

	unb = va_arg(arg, unsigned int);
	sum = 0;
	str = ft_utoa(unb);
	sum = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (sum);
}
