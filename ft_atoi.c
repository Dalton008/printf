/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:26:44 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/05 17:14:06 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

long int	ft_atoi(const char *str)
{
	long int	minus;
	long int	num_count;
	long int	result;

	minus = 1;
	result = 0;
	num_count = 19;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		minus = minus * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		if (!num_count--)
			return ((1 + minus) / (-2));
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * minus);
}
