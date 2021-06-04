/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:52:36 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 13:42:06 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

void	printf_prefix(void)
{
	char	*pr;
	int		n;

	n = 0;
	pr = "0x";
	while (n < 2)
		print_count(pr[n++], 1);
}

void	print_p_with_minus(unsigned long long nbr, t_spec *spec)
{
	spec->type = 'x';
	ft_print_hex(nbr, spec);
	if (spec->width > hex_len(nbr))
		ft_print_spec(spec->width, hex_len(nbr) + 1, ' ');
}

void	ft_proc_p(unsigned long long nbr, t_spec *spec)
{
	if ((!nbr || nbr == 0) && spec->precision == 0)
	{
		if (spec->width)
			ft_print_spec(spec->width, 1, ' ');
		return (printf_prefix());
	}
	if (spec->minus)
	{
		printf_prefix();
		print_p_with_minus(nbr, spec);
	}
	else
	{
		if (spec->width > num_len(nbr))
			ft_print_spec(spec->width, hex_len(nbr) + 1, ' ');
		if (spec->precision > num_len(nbr))
		{
			printf_prefix();
			ft_print_spec(spec->precision, hex_len(nbr) - 1, '0');
		}
		else
			printf_prefix();
		spec->type = 'x';
		ft_print_hex(nbr, spec);
	}
}
