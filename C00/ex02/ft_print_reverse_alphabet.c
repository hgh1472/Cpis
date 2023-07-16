#include <stdio.h>
#include <unistd.h>

void ft_print_reverse_alphabet(void) {
	char a = 'z';
	for (int i = 25;i>=0;i--) {
		write(1,&a,1);
		a--;
	}
}

int main() {
	ft_print_reverse_alphabet();
	return 0;
}
