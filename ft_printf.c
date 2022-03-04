#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar(nb + '0');
	}
}

int	check_base(char *base)
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

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size_base])
			size_base++;
		while (nbr > size_base - 1)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		write(1, "0x", 2);
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}

void	ft_check_and_print(va_list arg_p, char *format, int i)
{
	if (format[i] == '%')
		ft_putchar('%');
	else if (format[i] == 'c')
		ft_putchar(va_arg(arg_p, int));
	else if (format[i] == 'd')
		ft_putnbr(va_arg(arg_p, int));
	else if (format[i] == 's')
		ft_putstr(va_arg(arg_p, char *));
	else if (format[i] == 'o')
		ft_putnbr_base(va_arg(arg_p, int), "01234567");
	else if (format[i] == 'u')
		ft_putnbr_base(va_arg(arg_p, int), "0123456789");
	else if (format[i] == 'x')
		ft_putnbr_base(va_arg(arg_p, int), "0123456789abcdef");
	else if (format[i] == 'X')
		ft_putnbr_base(va_arg(arg_p, int), "0123456789ABCDEF");
	else if (format[i] == 'p')
		ft_putnbr_base(va_arg(arg_p, unsigned long long), "0123456789abcdef");
}

void	ft_printf(char *format, ...)
{
	va_list	arg_p;
	int		i;

	i = 0;
	va_start(arg_p, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_and_print(arg_p, format, i);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg_p);
}

// le return est le nombre de char ecrits

int main()
{
	char *y = "Je m'en vais tres loin";
	int x = 24;
    ft_printf("Hello world! %x\n%p\n", 187, &x);
    printf("Hello world! %x\n%p\n", 187, &x);

    return 0;
}
