#include "ft_printf.h"

# include <stdio.h>

int main()
{
	char *y = "Je m'en vais loin";
	char *z = "0101";
	double x = 24;
	int tab[1];
	tab[0] = 0;

	printf("%d\n", printf("real ptf: %x\n%p\n", -187, &x));
 	printf("%d\n", ft_printf("my ptf: %x\n%p\n", -187, &x));

	ft_printf("%d\n", ft_printf("my ptf:  %p\n", &x));
	printf("real ptf: %p\n", &x);

	printf("real ptf: %d\n", printf("%d\n", -2147483648));
	ft_printf("my ptf: %d\n", ft_printf("%d\n", -2147483648));
	return (0);
}
