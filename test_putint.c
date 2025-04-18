#include <stdio.h>
#include <limits.h>

int	ft_putint(int n);
int	ft_putunint(unsigned n);
int	main()
{
	printf("%d", ft_putint(INT_MAX));
	printf("%d", ft_putunint(UINT_MAX));
	return (0);
}
