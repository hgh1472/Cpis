#include <stdio.h>
#include <unistd.h>

void ft_print_numbers(void) {
	char a = '0';
	for (int i = 0;i<10;i++) {
		write(1,&a,1);
		a++;
	}
}

int main() {
	ft_print_numbers();
	return 0;
}
