#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int nb);

int main() {
	int n = -2147483648;
	ft_putnbr(n);
	return 0;
}

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putnbr(int nb) {
	char a;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb <0) 
	{
		ft_putchar('-');
		ft_putnbr((-1) * nb);
	}
	else 
	{
		if (nb / 10 != 0) 
		{
			ft_putnbr(nb/10);
		}
		ft_putchar('0' + (nb%10));
		nb /= 10;
	}
}
