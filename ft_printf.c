/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:48:35 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 13:56:38 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

void	ft_type_proces(va_list args, t_spec *spec)
{
	if (spec->type == 's')
		ft_proc_s(va_arg(args, char *), spec);
	else if (spec->type == 'c')
		ft_proc_c((char)va_arg(args, int), spec);
	if (spec->type == 'd')
		ft_proc_d(va_arg(args, int), spec);
	else if (spec->type == 'i')
		ft_proc_d(va_arg(args, int), spec);
	else if (spec->type == 'u')
		ft_print_u(va_arg(args, unsigned int), spec);
	else if (spec->type == 'x')
		ft_proc_hex(va_arg(args, unsigned int), spec);
	else if (spec->type == 'X')
		ft_proc_hex(va_arg(args, unsigned int), spec);
	else if (spec->type == 'p')
		ft_proc_p(va_arg(args, unsigned long long), spec);
	else if (spec->type == '%')
		ft_proc_c('%', spec);
}

t_spec	parse_input(const char *input, va_list args)
{
	t_spec	spec;

	init_spec(&spec);
	parse_flags(&spec, input);
	parse_width(args, &spec, input);
	parse_precision(args, &spec, input);
	parse_type(&spec, input);
	return (spec);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	t_spec	spec;
	int		n;

	n = 0;
	va_start(args, input);
	while (input[n])
	{
		if (input[n] == '%' && input[n + 1])
		{
			spec = parse_input(input + n + 1, args);
			ft_type_proces(args, &spec);
			n = n + spec.skip;
		}
		else
			print_count(input[n], 1);
		n++;
	}
	va_end(args);
	return (print_count('x', 0));
}
