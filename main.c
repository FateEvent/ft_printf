#include "ft_printf.h"

# include <stdio.h>

int main()
{
	char *y = "Je m'en vais loin";
	char *z = "0101";
	unsigned int x = 24;
	int tab[1];
	tab[0] = 0;
//	ft_printf("%d\n%i\n%d\n%i\n%d\n%i\n%d\n", 1, 5, 8, 9, 15, 90, -2147483648);
//	ft_printf("%o\n%o\n%o\n%o\n%o\n%o\n", 1, 5, 8, 9, 15, 90);
//	printf("%o\n%o\n%o\n%o\n%o\n%o\n", 1, 5, 8, 9, 15, 90);
//	ft_printf("%d\n", ft_printf("my ptf: %d\n%p\n%x\n%o\n", -2147483648, &x, -187, 15));
//	printf("%d\n", printf("real ptf: %d\n%p\n%x\n%o\n", -2147483648, &x, -187, 15));
//	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("a: %u", -1);
	printf("b: %u", -1);
	return (0);
}
