/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:19:02 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/01 20:22:14 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

void	ft_print_spec(int val, int size, char x)
{
	while (val - size > 1)
	{
		print_count(x, 1);
		val--;
	}
}

int	num_len(long int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num / 10 > 0)
	{
		num = num / 10;
		len++;
	}
	len++;
	return (len);
}

int	hex_len(unsigned long long num)
{
	unsigned long long	len;

	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num / 16 > 0)
	{
		num = num / 16;
		len++;
	}
	len++;
	return (len);
}

int	print_count(char c, int flag)
{
	static int	count;
	int			result;

	if (flag)
	{
		ft_putchar(c);
		count++;
	}
	else
	{
		result = count;
		count = 0;
		return (result);
	}
	return (1);
}
