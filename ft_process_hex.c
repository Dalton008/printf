/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:55:03 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 11:46:23 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

void	ft_print_hex(unsigned long long nbr, t_spec *spec)
{
	unsigned int	basetype;
	char			*hex_str;
	int				len;

	if (spec->type == 'x')
		hex_str = "0123456789abcdef";
	else if (spec->type == 'X')
		hex_str = "0123456789ABCDEF";
	len = 0;
	basetype = 16;
	if (nbr > basetype - 1)
	{
		ft_print_hex(nbr / basetype, spec);
		print_count(hex_str[nbr % basetype], 1);
		len++;
	}
	else
		print_count(hex_str[nbr], 1);
}

void	ft_proc_hex(unsigned int nbr, t_spec *spec)
{
	if (hex_len(nbr) == 1 && spec->zero && spec->precision < 0)
		ft_print_spec(spec->width, 0, '0');
	else
	{
		if (nbr == 0 && spec->precision == 0)
		{
			ft_print_spec(spec->width + 1, 0, ' ');
			return ;
		}
		if (spec->precision >= 0)
			spec->zero = 0;
		if (spec->minus != 0)
			spec->zero = 0;
		if (spec->precision < hex_len(nbr))
			spec->precision = hex_len(nbr);
		if (!spec->minus && !spec->zero && spec->precision > 0)
			ft_print_spec(spec->width, spec->precision - 1, ' ');
		if (!spec->minus && spec->zero)
			ft_print_spec(spec->width, spec->precision - 1, '0');
		ft_print_spec(spec->precision, hex_len(nbr) - 1, '0');
	}
	ft_print_hex(nbr, spec);
	if (spec->minus && spec->precision > 0)
		ft_print_spec(spec->width, spec->precision - 1, ' ');
}
