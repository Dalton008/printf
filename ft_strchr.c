/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:44:44 by mjammie           #+#    #+#             */
/*   Updated: 2021/05/08 13:07:30 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

char	ft_strchr_check(const char *str, int c)
{
	int		n;

	n = 0;
	while (str[n])
	{
		if (str[n] == c)
			return (1);
		n++;
	}
	return (0);
}
