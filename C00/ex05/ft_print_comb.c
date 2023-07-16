#include <stdio.h>
#include <unistd.h>

void ft_print_comb(void);

int main() {
	ft_print_comb();
	return 0;
}

void ft_print_comb(void) {
	char a[3];
	char b[2] = {',',' '};
	int sum=0;
	int copy;

	for (int i = 0;i<999;i++) {
		sum++;
		copy = sum;
		a[2] = '0' + (copy % 10);
		copy /= 10;
		a[1] = '0' + (copy % 10);
		a[0] = '0' + (copy / 10);
		if (a[0] < a[1] && a[1] < a[2]) {
			 if (sum != 12) {
                                write(1,&b,2);
                        }
                        write(1,&a,3);
		}
	}
}
