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

int	ft_putchar_count(char c, int *n_char)
{
	write(1, &c, 1);
	(*n_char)++;
	return (*n_char);
}

int	ft_putstr_count(char *str, int *n_char)
{
	while (*str != '\0')
	{
		ft_putchar_count(*str, n_char);
		str++;
	}
	return (*n_char);
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

int	ft_putnbr_base_count(unsigned int nbr, char *base, int *n_char)
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
			ft_putchar_count('-', n_char);
		}
		while (nbr > 0)
		{
			ret[i] = nbr % size_base;
			nbr /= size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar_count(base[ret[i]], n_char);
	}
	return (*n_char);
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
		while (--i >= 0)
			ft_putchar(base[ret[i]]);
	}
}

int	ft_putaddr_count(unsigned long long nbr, int *n_char)
{
	int	i;
	int	ret[100];

	while (nbr)
	{
		ret[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	write(1, "0x", 2);
	*n_char += 2;
	while (--i >= 0)
		ft_putchar_count("0123456789abcdef"[ret[i]], n_char);
	return (*n_char);
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
	while (--i > 0)
		ft_putchar("0123456789abcdef"[ret[i]]);
}

int	ft_check_and_print(va_list arg_p, char *format, int i, int *n_char)
{
	if (format[i] == '%')
		ft_putchar_count('%', n_char);
	else if (format[i] == 'c')
		ft_putchar_count(va_arg(arg_p, int), n_char);
	else if (format[i] == 'd')
		ft_putnbr_base_count(va_arg(arg_p, int), "0123456789", n_char);
	else if (format[i] == 's')
		ft_putstr_count(va_arg(arg_p, char *), n_char);
	else if (format[i] == 'o')
		ft_putnbr_base_count(va_arg(arg_p, int), "01234567", n_char);
	else if (format[i] == 'u')
		ft_putnbr_base_count(va_arg(arg_p, int), "0123456789", n_char);
	else if (format[i] == 'x')
		ft_putnbr_base_count(va_arg(arg_p, int), "0123456789abcdef", n_char);
	else if (format[i] == 'X')
		ft_putnbr_base_count(va_arg(arg_p, int), "0123456789ABCDEF", n_char);
	else if (format[i] == 'p')
		ft_putaddr_count(va_arg(arg_p, unsigned long long), n_char);
	return (*n_char);
}

int	ft_printf(char *format, ...)
{
	va_list	arg_p;
	int		tab[1];
	int		i;

	tab[0] = 0;
	i = 0;
	va_start(arg_p, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_and_print(arg_p, format, i, &tab[0]);
		}
		else
			ft_putchar_count(format[i], &tab[0]);
		i++;
	}
	va_end(arg_p);
	return (tab[0]);
}
// putaddr marche mais putaddr_count en fait des siennes
// le return est le nombre de char ecrits

int main()
{
	char *y = "Je m'en vais loin";
	char *z = "0101";
	double x = 24;
	int tab[1];
	tab[0] = 0;

	printf("%d\n", printf("%x\n%p\n", -187, &x));
 	printf("%d\n", ft_printf("%x\n%p\n", -187, &x));
//	printf(" char %d \n", ft_putchar_count('c', &tab[0]));
//	printf(" str %d \n", ft_putstr_count("hello worlds", &tab[0]));
//	printf(" nbr %d \n", ft_putnbr_base_count(206767877, "01234567", &tab[0]));
	ft_printf("%d\n", ft_printf("%p\n", &x));
	printf("%p\n", &x);
	return (0);
}
