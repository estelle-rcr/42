#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
//	unsigned int i = -67276;
//	int x = 7;
//	char *s = NULL;
//	char c;
	char *ptr;
	int ret1;
	int ret2;

	ptr = ft_strjoin("hello ", "world!");

/*	c = 'c';
	ret1 = ft_printf("hello %*s !\n", 20, s);
	ret2 = printf("hello %*p !\n", 20, s);
	printf("ret1 %i ret2 %i\n", ret1, ret2);

 	if (str == NULL)
		str = "(null)";*/ 


	ret1 = ft_printf("%-*p\n", 30, ptr);
	ret2 = printf("%-*p\n", 30, ptr); 
	printf("ret1 %i ret2 %i\n", ret1, ret2);

//	HEX:	
/*	printf("%04x", 4779); // gives 12ab
	printf("%x", 4779); // gives 12ab
	printf("%#010x\n", x);  // gives 0x00000007
	printf("0x%08x\n", x);  // gives 0x00000007
	printf("%#08x\n", x);   // gives 0x000007
*/
//	INTEGER:	
/*	printf("Hello %-0*i !\n", 8, i);
	printf("Hello %.0i !\n", i);
	printf("Hello %6i !\n", 2021);
	printf("Hello %0*i !\n", 5, 2021);
	printf("Hello %@*i !\n", 5, 2021);
	printf("Hello %0*i !\n", 6, 2021);
	printf("Hello %-0*i !\n", 6, 2021);
	printf("Hello %-*i !\n", 6, 2021);
	printf("%.5d\n", -3);  // use of precision filed
	printf("%05d\n", -3);	*/
	return (0);
}
