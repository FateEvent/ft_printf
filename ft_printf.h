/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:18:37 by faventur          #+#    #+#             */
/*   Updated: 2022/03/07 15:00:03 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_count(char c, int *n_char);
int		ft_putstr_count(char *str, int *n_char);
int		ft_putaddr_count(unsigned long long nbr, int *n_char);
int		ft_putnbr_count(int nbr, char *base, int *n_char);
int		ft_puthexa(unsigned int nbr, char *base, int *n_char);
int		ft_put_unsigned(unsigned int nbr, char *base, int *n_char);
int		ft_check_and_print(va_list arg_p, char *format, int i, int *n_char);
int		ft_printf(char *format, ...);

#endif