#include "ex01/ft_strncpy.c"
#include <stdio.h>
#include <string.h>

int	main(void)
{	
	printf("-ex01_test_case-\n\n");
	char dest2[10] = "Howareyou";
	char src2[6] = "Hello";
	printf("input dest : Howareyou | src : Hello |  n : 5\n\n");
	printf("--answer--\nstrncpy : %s ft_strncpy : %s\n\n", strncpy(dest2, src2, 5), ft_strncpy(dest2, src2, 5));
	printf("input  dest : Howareyou | src : Hello | n : 10\n\n");
	printf("--answer--\nstrncpy : %s ft_strncpy : %s", strncpy(dest2, src2, 10), ft_strncpy(dest2, src2, 10));
	printf("\n\n------------------------------\n\n");
	return 0;
}
