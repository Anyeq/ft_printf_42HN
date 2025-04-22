#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "libftprintf.h"
//int	ft_putint(int n);
//int	ft_putunint(unsigned n);
//int	ft_putnum_base(unsigned int n, int nbase, const char *base);
//int	ft_putptr(void *n);
//int	ft_putstr(const char *s, int precision);
//int	ft_putchar(unsigned int s);
int	ft_printf(const char *fmt, ...);

int	main(void)
{
	int	i;

	i = 0;
//	printf("%d\n", ft_putint(INT_MAX));
//	printf("%d\n", ft_putunint(UINT_MAX));
//	printf("%d\n", ft_putnum_base(0, 16, "0123456789ABCDEF"));
//	printf("%d\n", ft_putptr(&i));
//	printf("%d\n", ft_putstr("Hello World", 0));
//	printf("%d\n", ft_putchar('A'));
//	printf("%p\n", &i);
	printf("============================");
	printf("============================");
	printf("\n%d", ft_printf("Test --> %s hallo\n", "Hello world"));
	printf("\n%d", ft_printf("Test --> %p hallo\n", &i));

	return (0);
}
