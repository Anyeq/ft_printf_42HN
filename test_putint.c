#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int	ft_putint(int n);
int	ft_putunint(unsigned n);
int	ft_putnum_base(unsigned int n, int nbase, const char *base);
int	ft_putptr(void *n);

int	main(void)
{
	int	i;

	i = 0;
	printf("%d\n", ft_putint(INT_MAX));
	printf("%d\n", ft_putunint(UINT_MAX));
	printf("%d\n", ft_putnum_base(0, 16, "0123456789ABCDEF"));
	printf("%d\n", ft_putptr(&i));
	printf("%p\n", &i);

	return (0);
}
