/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 10:29:09 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 13:07:20 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int			ft_strlen(const char *str);
void		ft_putchar(char c);
void		ft_putnbr(long int n);
void		ft_putstr(char *s);
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);
void		ft_putnbr_u(unsigned int n);
char		ft_strchr_check(const char *str, int c);

#endif