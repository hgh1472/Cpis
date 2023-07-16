#include <stdio.h>
#include <unistd.h>

void ft_is_negative(int n);

int main() {
	int a = 5;
	ft_is_negative(a);
	return 0;
}

void ft_is_negative(int n) {
	char a[2] = {'N','P'};
	if (n>=0) {
		write(1,&a[1],1);
	}
	else {
		write(1,&a[0],1);
	}
}		
