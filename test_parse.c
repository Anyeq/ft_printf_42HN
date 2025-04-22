#include "./libft/libft.h"
#include <stdio.h>
//#include "libftprintf.h"

//t_prse *parse_format(const char *fmt_str, int *iter);
int	main(void)
{
	//t_prse	*test;
	char *str;
	int	i;

	str = "Hello world";
	i = 0;
	//printf("Testing %%c\n");
	//printf("===================\n");
	//printf("Plain ==> %c\n", 'A');
	//printf("Space ==> % c\n", 'A');
	//printf("Dot   ==> %.c\n", 'A');
	//printf("prcs  ==> %.0c\n", 'A');
	//printf("width ==> %5c\n", 'A');
	//printf(" #    ==> %#c\n", 'A');
	//printf(" 0    ==> %05c\n", 'A');
	//printf(" -    ==> %-5c\n", 'A');
	//printf(" +    ==> %+c\n", 'A');
	//printf(" comb ==> %0+-c\n", 'A');
	//printf("Testing %%s\n");
	//printf("===================\n");
	//printf("Plain ==> %s\n", str);
	//printf("Space ==> % s\n", str);
	//printf("Dot   ==> %.s\n", str);
	//printf("prcs  ==> %.0s\n", str);
	//printf("width ==> %5s\n", str);
	//printf(" #    ==> %#s\n", str);
	//printf(" 0    ==> %05s\n", str);
	//printf(" -    ==> %-5s hi\n", str);
	//printf(" +    ==> %+s\n", str);
	printf(" comb ==> %13.15s hi\n", str);
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
	//printf("%p\n", &i);
	//i = printf("%.20s", str);
	//printf("%-05d", i);
	//printf("%s\n", str);
	//printf("%0#7x", 12376890);
	//free(test);
	return (0);
}
