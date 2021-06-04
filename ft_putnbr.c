/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:15:52 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/05 18:33:28 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

void	ft_putnbr(long int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		print_count('-', 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	print_count((char)(n % 10 + 48), 1);
}

void	ft_putnbr_u(unsigned int n)
{
	int		i;

	i = 0;
	if (n >= 10)
		ft_putnbr_u(n / 10);
	print_count((char)(n % 10 + 48), 1);
}
