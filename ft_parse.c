/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:27:07 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 13:06:28 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

void	init_spec(t_spec *spec)
{
	spec->type = 0;
	spec->width = 0;
	spec->minus = 0;
	spec->zero = 0;
	spec->precision = -1;
	spec->star = 0;
	spec->space = 0;
	spec->hash = 0;
	spec->plus = 0;
	spec->skip = 0;
	spec->dot = 0;
	spec->plus = 0;
}

void	parse_flags(t_spec *spec, const char *input)
{
	int	n;

	n = 0;
	while (1)
	{
		if (input[n] == '-')
			spec->minus = 1;
		else if (input[n] == '0')
			spec->zero = 1;
		else
			break ;
		n++;
	}
	spec->skip = n;
}

void	parse_width(va_list args, t_spec *spec, const char *input)
{
	if (input[spec->skip] == '*')
	{
		spec->width = va_arg(args, int);
		if (spec->width < 0)
		{
			spec->minus = 1;
			spec->width = -spec->width;
		}
		spec->skip++;
		return ;
	}
	spec->width = ft_atoi(&input[spec->skip]);
	while (ft_isdigit(input[spec->skip]))
		spec->skip++;
}

void	parse_precision(va_list args, t_spec *spec, const char *input)
{
	if (input[spec->skip] == '.')
		spec->skip++;
	else
		return ;
	if (input[spec->skip] == '*')
	{
		spec->precision = va_arg(args, int);
		spec->skip++;
		return ;
	}
	spec->precision = ft_atoi(&input[spec->skip]);
	while (ft_isdigit(input[spec->skip]))
		spec->skip++;
}

void	parse_type(t_spec *spec, const char *input)
{
	if (ft_strchr_check("cspdiuxX%", input[spec->skip]))
	{
		spec->type = input[spec->skip];
		spec->skip++;
	}
	else
		return ;
}
