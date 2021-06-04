/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:55:47 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 11:48:50 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

void	ft_print_no_pre(t_spec *spec)
{
	while (spec->width--)
		print_count(' ', 1);
}

void	ft_print_u(unsigned int num, t_spec *spec)
{
	if (num == 0 && spec->precision == 0)
		return (ft_print_no_pre(spec));
	else
	{
		if (spec->precision >= 0)
			spec->zero = 0;
		if (spec->minus != 0)
			spec->zero = 0;
		if (spec->precision < num_len(num))
			spec->precision = num_len(num);
		if (!spec->minus && !spec->zero)
			ft_print_spec(spec->width, spec->precision - 1, ' ');
		if (!spec->minus && spec->zero)
			ft_print_spec(spec->width, spec->precision - 1, '0');
		ft_print_spec(spec->precision + 1, num_len(num), '0');
		ft_putnbr_u(num);
		if (spec->minus)
			ft_print_spec(spec->width, spec->precision - 1, ' ');
	}
}

void	ft_proc_d(long int num, t_spec *spec)
{
	if (num >= 0)
		ft_print_u((unsigned int)num, spec);
	else
	{	
		if (num == 0 && spec->precision == 0)
			return (ft_print_no_pre(spec));
		num = -num;
		if (spec->precision >= 0 || spec->minus)
			spec->zero = 0;
		if (spec->precision < num_len(num))
			spec->precision = num_len(num);
		if (spec->zero)
			print_count('-', 1);
		if (!spec->minus && !spec->zero)
			ft_print_spec(spec->width, spec->precision, ' ');
		if (!spec->minus && spec->zero)
			ft_print_spec(spec->width, spec->precision, '0');
		if (!spec->zero)
			print_count('-', 1);
		ft_print_spec(spec->precision + 1, num_len(num), '0');
		ft_putnbr(num);
		if (spec->minus)
			ft_print_spec(spec->width, spec->precision, ' ');
	}
}
