#include "libft.h"

static void	ft_reverse(char *res, char *num, int i)
{
	int	j;
	int	a;

	j = i;
	a = 0;
	if (num[0] == '-')
	{
		res[0] = num[0];
		a = 1;
	}
	while (i > 0)
	{
		res[j - i + a] = num[i - 1];
		i--;
	}
	res[j] = '\0';
}

static void	ft_check_num(long long *n, char *char_num, int *i)
{
	char_num[0] = '-';
	*i = 1;
	*n = *n * -1;
}

char	*ft_ntoa(long long n, int base, char *str_format)
{
	char	*num_string;
	char	char_num[20];
	int	i;

	i = 0;
	if (n < 0)
		ft_check_num(&n, char_num, &i);
	while (n > 0)
	{
		char_num[i] = str_format[n % base];
		i++;
		n = n / base;
	}
	char_num[i] = '\0';
	num_string = malloc(i * sizeof(char));
	ft_reverse(num_string, char_num, i);
	return (num_string);
}
