#include <stdio.h>
#include <unistd.h>

void ft_print_combn(int n);
void print(char a[],int n);
int check(char a[],int n);

int main() {
	int n = 3;
	ft_print_combn(n);
	return 0;
}

int max_num(int n)
{
	int max=1;
	for (int i = 0;i<n;i++)
	{
		max *= 10;
	}
	return max;
}

void print(char a[],int n)
{
	char dot;
	char space;

	dot = ',';
	space = ' ';
	for (int i = 0;i<n;i++)
	{
		write(1,&a[i],1);
	}
	if  (a[0] != '0' + (10 -n))
	{
		write(1,&dot,1);
		write(1,&space,1);
	}
}

int check(char a[],int n)
{
	int flag;

	flag = 0;
	for (int i = 0;i<n;i++)
	{
		for (int j = i+1;j<n;j++)
		{
			if (a[i] >= a[j])
			{
				flag = 1;
			}
		}
	}
	return flag;
}

void ft_print_combn(int n) {
	char a[10];
	int max_number;
	int num;
	int copy;

	num =0;
	max_number = max_num(n);
	for (int i = 0;i < max_number;i++)
	{
		copy = num;
		for (int i = 0;i<n;i++)
		{
			a[n-1-i] = '0' + copy % 10;
			copy /= 10;
		}
		if (check(a,n) == 0)
		{
			print(a,n);
		}
		num++;
	}
}



