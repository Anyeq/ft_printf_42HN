#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	int	i;

	i = 0;
	int a;
	int b;
	int c;
	int d;
	int f;
	int g;
	int h;
	int j;
	int k;
//	printf("%d\n", ft_putint(INT_MAX));
//	printf("%d\n", ft_putunint(UINT_MAX));
//	printf("%d\n", ft_putnum_base(0, 16, "0123456789ABCDEF"));
//	printf("%d\n", ft_putptr(&i));
//	printf("%d\n", ft_putstr("Hello World", 0));
//	printf("%d\n", ft_putchar('A'));
//	printf("%p\n", &i);
	//printf("\n%d", ft_printf("Test --> %s hallo\n", "Hello world"));
	//printf("\n%d", ft_printf("Test --> %p hallo\n", &i));
	a = ft_printf("Hello world %10c alex\n", 'C');
	b = ft_printf("Hello world %-10.5s alex\n", "Hello");
	c = ft_printf("Hello world %+10.5d alex\n", 42);
	d = ft_printf("Hello world %010.5d alex\n", -42);
	f = ft_printf("Hello world %20.11u alex\n", 3000000000);
	g = ft_printf("Hello world %10p alex\n", NULL);
	g = ft_printf("Hello world %015p alex\n", &i);
	h = ft_printf("Hello world %#x alex\n", i);
	j = ft_printf("Hello world %#X alex\n", i + 4242);
	k = printf("Hello world %10.5d alex\n", -42);
	printf("Hello world %-10.5s alex\n", "Hello");
	printf("Hello world %10p alex\n", NULL);
	printf("Hello world %015p alex\n", &i);
	printf("Hello world %20.11u alex\n", (unsigned int)3000000000);
	printf("Hello world %#x alex\n", 2340598);
	printf("Hello world %#X alex\n", i + 4242);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", f);
	printf("%d\n", g);
	printf("%d\n", h);
	printf("%d\n", j);
	k = printf("Hello world %-10.5d alex\n", -42);
	printf("%d", k);
	//printf("hello world %");
	//ft_printf("This is a charachter ==> %05c\n", 'A');
	//ft_printf("This is a string ==> %13.15s\n", "Hello world");
	//ft_printf("This is a pointer ==> %.20p hi\n", &i);
	//ft_printf("This is a pointer ==> %p\n", &i);
	//ft_printf("This is a pointer ==> %-15p\n", NULL);
	//ft_printf("This is a int ==> %5i\n", -42);
	//ft_printf("This is a int ==> %+5.3d\n", 42);
	//ft_printf("This is a uint ==> %5u\n", 42);
	//ft_printf("This is a uint ==> %+5.3u\n", 2999999999 + 2);
	//ft_printf("This is a hex ==> %5x\n", -42);
	//ft_printf("This is a hex ==> %+5.3x\n", 42);
	//ft_printf("This is a HEX ==> %5X\n", -42);
	//ft_printf("This is a HEX ==> %+5.3X\n", 42);
	return (i);
}
