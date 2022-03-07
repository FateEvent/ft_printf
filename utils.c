/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:39 by faventur          #+#    #+#             */
/*   Updated: 2022/03/07 16:18:54 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_count(char c, int *n_char)
{
	write(1, &c, 1);
	(*n_char)++;
	return (*n_char);
}

int	ft_putstr_count(char *str, int *n_char)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*n_char += 6;
		return (*n_char);
	}
	while (*str != '\0')
	{
		ft_putchar_count(*str, n_char);
		str++;
	}
	return (*n_char);
}
