#include <stdio.h>
#include <unistd.h>

void ft_print_alphabet(void) {
	char a = 'a';
	for (int i = 0;i<26;i++) {
		write(1,&a,1);
		a++;
	}
}
