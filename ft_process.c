/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:09:57 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 13:26:10 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

int	ft_print_pre(char *str, t_spec *spec)
{
	int	n;

	n = 0;
	if (spec->precision == 0 && ft_strlen(str) >= 1)
		ft_print_spec(spec->width, spec->precision - 1, ' ');
	while (spec->precision > 0)
	{
		spec->precision--;
		print_count(str[n], 1);
		n++;
	}
	spec->width = spec->width - n + 1;
	return (n);
}

void	ft_proc_s(char *str, t_spec *spec)
{
	int	n;

	n = 0;
	if (!str)
		return (ft_proc_s("(null)", spec));
	if (ft_strlen(str) == 0)
		ft_print_spec(spec->width + 1, 0, ' ');
	if (spec->precision > ft_strlen(str))
		spec->precision = ft_strlen(str);
	if (!spec->minus && spec->precision < 0 && !spec->zero)
		ft_print_spec(spec->width, ft_strlen(str) - 1, ' ');
	if (!spec->minus && spec->precision < 0 && spec->zero)
		ft_print_spec(spec->width, ft_strlen(str) - 1, '0');
	if (!spec->minus && spec->precision > 0)
		ft_print_spec(spec->width, spec->precision - 1, ' ');
	if (spec->precision >= 0)
		n = ft_print_pre(str, spec);
	else
		ft_putstr(str);
	if (spec->width && spec->minus && n > 0 && ft_strlen(str) > 1)
		ft_print_spec(spec->width, spec->precision, ' ');
	else if (spec->width && spec->minus && n > 0 && ft_strlen(str) == 1)
		ft_print_spec(spec->width + 1, ft_strlen(str), ' ');
	else if (spec->width && spec->minus && spec->precision != 0)
		ft_print_spec(spec->width + 1, ft_strlen(str), ' ');
}

void	ft_proc_c(char c, t_spec *spec)
{
	if (spec->minus)
	{
		spec->zero = 0;
		print_count(c, 1);
		while (spec->width > 1)
		{
			print_count(' ', 1);
			spec->width--;
		}
		return ;
	}
	if (spec->zero)
	{
		while (spec->width > 1)
		{
			print_count('0', 1);
			spec->width--;
		}
	}
	while (spec->width > 1)
	{
		print_count(' ', 1);
		spec->width--;
	}
	print_count(c, 1);
}
