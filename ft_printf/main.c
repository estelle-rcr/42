#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int ret1;
	int ret2;
	int i = -67276;
	int x = 7;
	char *s = NULL;
	char *t;
	char c = '\0';
	char *ptr = NULL;
	unsigned int hex = 456789;


	t = ft_joinstr("hello ", "world!");

	printf("\nTests STRING & POINTER & CHAR:\n");	
	ret1 = ft_printf("test1 %*.*s !\n", -20, 10, s);
	ret2 = printf("test1 %*.*s !\n", -20, 10, s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %-.*s !\n", 20, t);
	ret2 = printf("hello %-.*s !\n", 20, t);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("test2 %-*p !\n", 400, s);
	ret2 = printf("test2 %-*p !\n", 400, s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("test2 %-*p !\n", 400, ptr);
	ret2 = printf("test2 %-*p !\n", 400, ptr);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %*c !\n", 20, c);
	ret2 = printf("hello %*c !\n", 20, c);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %.*% !\n", 20);
	ret2 = printf("hello %.*% !\n", 20);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	printf("\nTests HEX:\n");	
	ret1 = ft_printf("%*.*X \n", 30, -10, hex);
	ret2 = printf("%*.*X \n", 30, -10, hex); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%04x\n", 4779); 
	ret2 = printf("%04x\n", 4779); // gives 12ab
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%x\n", 4779); 
	ret2 = printf("%x\n", 4779); // gives 12ab	
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%#010x\n", x); 
	ret2 = printf("%#010x\n", x);  // gives 0x00000007	
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("0x%08x\n", x); 
	ret2 = printf("0x%08x\n", x);  // gives 0x00000007
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%#08x\n", x); 
	ret2 = printf("%#08x\n", x);   // gives 0x000007
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	printf("\nTests INTEGER:\n");	
	ret1 = ft_printf("Hello %0*i !\n", 8, i);
	ret2 = printf("Hello %0*i !\n", 8, i);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("Hello %.0i !\n", i);
	ret2 = printf("Hello %.0i !\n", i);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("Hello %6i !\n", 2021);
	ret2 = printf("Hello %6i !\n", 2021);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("Hello %0*i !\n", 5, 2021);
	ret2 = printf("Hello %0*i !\n", 5, 2021);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("Hello %0*i !\n", 6, 2021);
	ret2 = printf("Hello %0*i !\n", 6, 2021);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("Hello %-*i !\n", 6, 2021);
	ret2 = printf("Hello %-*i !\n", 6, 2021);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("Hello %-*i !\n", 6, 2021);
	ret2 = printf("Hello %-*i !\n", 6, 2021);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%.5d\n", -3);  // use of precision filed
	ret2 = printf("%.5d\n", -3);  // use of precision filed
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%05d \n", -3);
	ret2 = printf("%05d \n", -3);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	free(t);
	return (0);
}
