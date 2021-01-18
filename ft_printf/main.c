#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int ret1;
	int ret2;
	int i = -1;
	int a = 0;
	int j = 98;
	char *t;
	char c = '\0';
	char *s = NULL;
	char *z = "abc";

	printf("\nTests unsigned INT:\n");
	unsigned int u = 0;
	unsigned int un = 4294967295;
	unsigned int uns = 198;

	ret1 = ft_printf("-->|%-4u|<--\n", un);
	ret2 = printf("-->|%-4u|<--\n", un);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.u|<--\n", u);
	ret2 = printf("-->|%-4.u|<--\n", u);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.1u|<--\n", u);
	ret2 = printf("-->|%-4.1u|<--\n", u);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.*u|<--\n", -4, u);
	ret2 = printf("-->|%-4.*u|<--\n", -4, u);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.*u|<--\n", -3, u);
	ret2 = printf("-->|%-4.*u|<--\n", -3, u);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.*u|<--\n", -3, uns);
	ret2 = printf("-->|%-4.*u|<--\n", -3, uns);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%04.4u|<--\n", uns);
	ret2 = printf("-->|%04.4u|<--\n", uns);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%04.4u|<--\n", uns);
	ret2 = printf("-->|%04.4u|<--\n", uns);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%--4.u|<--\n", uns);
	ret2 = printf("-->|%--4.u|<--\n", uns);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%04u|<--\n", uns);
	ret2 = printf("-->|%04u|<--\n", uns);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.u|<--\n", u);
	ret2 = printf("-->|%-4.u|<--\n", u);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.*u|<--\n", 3, u);
	ret2 = printf("-->|%-4.*u|<--\n", 3, u);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%0*.u|<--\n", 3, u);
	ret2 = printf("-->|%0*.u|<--\n", 3, u);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	printf("\nTests STRING & POINTER & CHAR:\n");
	t = ft_joinstr("hello ", "world!");
	ret1 = ft_printf("%-16.s\n", s);
	ret2 = printf("%-16.s\n", s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-16.*s|<--\n", -4, s);
	ret2 = printf("-->|%-16.*s|<--\n", -4, s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("|%-6.s|", s);
	ret2 = printf("|%-6.s|", s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-16s|<--\n", s);
	ret2 = printf("-->|%-16s|<--\n", s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%16s|<--\n", s);
	ret2 = printf("-->|%16s|<--\n", s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%16.16s|<--\n", s);
	ret2 = printf("-->|%16.16s|<--\n", s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-16.*s|<--\n", 4, z);
	ret2 = printf("-->|%-16.*s|<--\n", 4, z);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%*.*s|<--\n", 4, 4, z);
	ret2 = printf("-->|%*.*s|<--\n", 4, 4, z);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("test1 %*.*s !\n", -20, 10, s);
	ret2 = printf("test1 %*.*s !\n", -20, 10, s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %-.*s !\n", 20, t);
	ret2 = printf("hello %-.*s !\n", 20, t);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("test2 %-*p !\n", 400, s);
	ret2 = printf("test2 %-*p !\n", 400, s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %*c !\n", 20, c);
	ret2 = printf("hello %*c !\n", 20, c);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %*.c !\n", 4, c);
	ret2 = printf("hello %*.c !\n", 4, c);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %0*.% !\n", 4);
	ret2 = printf("hello %0*.% !\n", 4);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	free(t);

	printf("\nTests POINTER:\n");
	char *p = NULL;

	ret1 = ft_printf("test2 %-*p !\n", 400, p);
	ret2 = printf("test2 %-*p !\n", 400, p);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-16.p|<--\n", p);
	ret2 = printf("-->|%-16.p|<--\n", p);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-15p|<--\n", p);
	ret2 = printf("-->|%-15p|<--\n", p);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	printf("\nTests %% :\n");
	ret1 = ft_printf("-->|%0*.*%|<--\n", 2, -4);
	ret2 = printf("-->|%0*.*%|<--\n", 2, -4);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%04.4%|<--\n");
	ret2 = printf("-->|%04.4%|<--\n");
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%04%|<--\n");
	ret2 = printf("-->|%04%|<--\n");
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%0*.*%|<--\n", 2, -4);
	ret2 = printf("-->|%0*.*%|<--\n", 2, -4);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%0*.%|<--\n", 3);
	ret2 = printf("-->|%0*.%|<--\n", 3);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.2%|<--\n");
	ret2 = printf("-->|%-4.2%|<--\n");
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%0*%|<--\n", -2);
	ret2 = printf("-->|%0*%|<--\n", -2);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%0*.%|<--\n", -4);
	ret2 = printf("-->|%0*.%|<--\n", -4);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%0*.4%|<--\n", -2);
	ret2 = printf("-->|%0*.4%|<--\n", -2);
	printf("ret1 %i ret2 %i\n", ret1, ret2);


	printf("\nTests HEX:\n");
	unsigned int hex = 456789;
	unsigned int he = 198;
	unsigned int x = 0;


	ret1 = ft_printf("%*.*X \n", 30, -10, hex);
	ret2 = printf("%*.*X \n", 30, -10, hex); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%04x\n", 4779); 
	ret2 = printf("%04x\n", 4779); // gives 12ab
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%x\n", 4779); 
	ret2 = printf("%x\n", 4779); // gives 12ab	
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%010x\n", x); 
	ret2 = printf("%010x\n", x);  // gives 0x00000007	
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("0x%08x\n", x); 
	ret2 = printf("0x%08x\n", x);  // gives 0x00000007
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%02x\n", x); 
	ret2 = printf("%02x\n", x);   // gives 0x000007
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("-->|%04.x|<--\n", he);
	ret2 = printf("-->|%04.x|<--\n", he); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	
	ret1 = ft_printf("-->|%04.x|<--\n", x);
	ret2 = printf("-->|%04.x|<--\n", x); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	printf("\nTests INTEGER:\n");
	int m = 4294967284;
	
	ret1 = ft_printf("Hello %1.0d !\n", m);
	ret2 = printf("Hello %1.0d !\n", m);
	printf("ret1 %i ret2 %i\n", ret1, ret2);


	int b = -2147483648;
	ret1 = ft_printf("Hello %0*i !\n", 8, b);
	ret2 = printf("Hello %0*i !\n", 8, b);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("Hello %.*i !\n", 12, b);
	ret2 = printf("Hello %.*i !\n", 12, b);
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
	ret1 = ft_printf("%.5d\n", -3);  
	ret2 = printf("%.5d\n", -3); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%05d \n", -3);
	ret2 = printf("%05d \n", -3);
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("-->|%04.i|<--\n", j);
	ret2 = printf("-->|%04.i|<--\n", j); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.*i|<--\n", 0, i);
	ret2 = printf("-->|%-4.*i|<--\n", 0, i); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.2i|<--\n", i);
	ret2 = printf("-->|%-4.2i|<--\n", i); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.1i|<--\n", a);
	ret2 = printf("-->|%-4.1i|<--\n", a); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.0i|<--\n", a);
	ret2 = printf("-->|%-4.0i|<--\n", a); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-*.0i|<--\n", 0, a);
	ret2 = printf("-->|%-*.0i|<--\n", 0, a);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4.4i|<--\n", a);
	ret2 = printf("-->|%-4.4i|<--\n", a); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("-->|%-4i|<--\n", a);
	ret2 = printf("-->|%-4i|<--\n", a); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);
	return (0);
}
