#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

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
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	size_base;
	int	i;
	int	ret[100];

	size_base = 0;
	i = 0;
	if (check_base(base))
	{
		while (base[size_base] != '\0')
			size_base++;
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-');
		}
		while (nbr > 0)
		{
			ret[i] = nbr % size_base;
			nbr /= size_base;
			i++;
		}
		while (ret[--i])
			ft_putchar(base[ret[i]]);
	}
}

void	ft_putaddr(unsigned long long nbr)
{
	int	i;
	int	ret[100];

	while (nbr)
	{
		ret[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	ft_putstr("0x");
	while (--i)
		ft_putchar("0123456789abcdef"[ret[i]]);
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
		ft_putaddr(va_arg(arg_p, unsigned long long));
}

int	ft_printf(char *format, ...)
{
	va_list	arg_p;
	int		tab[1];
	int		x;

	tab[0] = 0;
	x = 0;
	va_start(arg_p, format);
	while (format[tab[0]] != '\0')
	{
		if (format[tab[0]] == '%')
		{
			tab[0]++;
			ft_check_and_print(arg_p, format, tab[0]);
			x += 2;
		}
		else
			ft_putchar(format[tab[0]]);
		tab[0]++;
	}
	va_end(arg_p);
	tab[0] -= x;
	return (tab[0]);
}

// le return est le nombre de char ecrits

int main()
{
	char *y = "Je m'en vais loin";
	char *z = "0101";
	int x = 24;

	ft_printf("%d\n", ft_printf("%x\n%p\n", -187, &x));
	printf("%d", printf("%x\n%p\n", -187, &x));
	printf("%d", printf("%s\n", y));
	return (0);
}
