#include "./libft/libft.h"
#include <stdio.h>
#include "libftprintf.h"

//t_prse *parse_format(const char *fmt_str, int *iter);
int	main(void)
{
	//t_prse	*test;
	char *str;
	int	i;

	str = "Hello world";
	i = 0;
    //str = " 20d";
    //test = parse_format(str, &i);
    //printf("%d", 9);
    //printf("\n");
    //printf("%d", test->flag_zero);
    //printf("\n");
    //printf("%d", test->flag_minus);
    //printf("\n");
    //printf("%d", test->flag_hashtag);
    //printf("\n");
    //printf("%d", test->flag_space);
    //printf("\n");
    //printf("%d", test->flag_plus);
    //printf("\n");
    //printf("%d", test->flag_dot);
    //printf("\n");
    //printf("%zu", test->width);
    //printf("\n");
    //printf("%zu", test->precision);
    //printf("\n");
    //printf("%d", i);
    //printf("\n");
	printf("%p\n", &i);
	i = printf("%.20s", str);
	printf("%d", i);
	printf("%s\n", str);
	//printf("%0#7x", 12376890);
	//free(test);
	return (0);
}
