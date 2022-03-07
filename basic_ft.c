/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:34 by faventur          #+#    #+#             */
/*   Updated: 2022/03/07 15:03:51 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	ft_putaddr_count(unsigned long long nbr, int *n_char)
{
	int	i;
	int	ret[100];

	i = 0;
	while (nbr)
	{
		ret[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	ft_putstr_count("0x", n_char);
	while (--i >= 0)
		ft_putchar_count("0123456789abcdef"[ret[i]], n_char);
	return (*n_char);
}

int	ft_putnbr_count(int nbr, char *base, int *n_char)
{
	int			i;
	int			ret[100];
	long int	x;

	i = 0;
	x = nbr;
	if (x < 0)
	{
		x *= -1;
		ft_putchar_count('-', n_char);
	}
	while (x > 0)
	{
		ret[i] = x % 10;
		x /= 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_count(base[ret[i]], n_char);
	return (*n_char);
}

int	ft_puthexa(unsigned int nbr, char *base, int *n_char)
{
	int			i;
	int			ret[100];

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_count('-', n_char);
	}
	while (nbr > 0)
	{
		ret[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar_count(base[ret[i]], n_char);
	return (*n_char);
}

int	ft_put_unsigned(unsigned int nbr, char *base, int *n_char)
{
	int			size_base;
	int			i;
	int			ret[100];
	long int	x;

	size_base = 0;
	i = 0;
	x = nbr;
	if (x < 0)
	{
		x *= -1;
		ft_putchar_count('-', n_char);
	}
	while (x > 0)
	{
		ret[i] = x % size_base;
		x /= size_base;
		i++;
	}
	while (--i >= 0)
		ft_putchar_count(base[ret[i]], n_char);
	return (*n_char);
}
