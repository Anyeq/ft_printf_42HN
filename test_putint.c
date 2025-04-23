#include <stdio.h>
#include "libftprintf.h"

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
	//printf("\n%d", ft_printf("Test --> %s hallo\n", "Hello world"));
	//printf("\n%d", ft_printf("Test --> %p hallo\n", &i));
	ft_printf("Hello this is a test\n");
	ft_printf("This is a charachter ==> %05c\n", 'A');
	ft_printf("This is a string ==> %13.15s\n", "Hello world");
	ft_printf("This is a pointer ==> %.20p hi\n", &i);
	ft_printf("This is a pointer ==> %p\n", &i);
	ft_printf("This is a pointer ==> %-15p\n", NULL);

	return (i);
}
