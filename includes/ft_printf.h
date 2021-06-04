/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:07:29 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 12:50:43 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> //del

typedef struct s_spec
{
	int	minus;
	int	zero;
	int	dot;
	int	star;
	int	width;
	int	precision;
	int	type;
	int	space;
	int	hash;
	int	plus;
	int	skip;
}				t_spec;

void	ft_proc_s(char *str, t_spec *spec);
void	ft_proc_d(long int number, t_spec *spec);
void	ft_proc_c(char c, t_spec *spec);
void	ft_print_u(unsigned int num, t_spec *spec);
void	ft_proc_hex(unsigned int nbr, t_spec *spec);
void	ft_proc_p(unsigned long long nbr, t_spec *spec);
void	init_spec(t_spec *spec);
void	parse_flags(t_spec *spec, const char *input);
void	parse_width(va_list args, t_spec *spec, const char *input);
void	parse_precision(va_list args, t_spec *spec, const char *input);
void	parse_type(t_spec *spec, const char *input);
void	ft_print_spec(int val, int size, char x);
int		num_len(long int num);
void	printf_with_width(int number, t_spec *spec);
void	ft_print_hex(unsigned long long nbr, t_spec *spec);
int		hex_len(unsigned long long num);
void	print_with_minus(int number, t_spec *spec);
void	printf_with_width(int number, t_spec *spec);
void	print_with_zero(int number, t_spec *spec);
int		print_count(char c, int flag);

#endif