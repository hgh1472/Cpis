/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgh1472 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:20 by hgh1472           #+#    #+#             */
/*   Updated: 2023/07/08 16:56:14 by hgh1472          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_print_comb2(void);

int main() {
	ft_print_comb2();
	return 0;
}

void ft_print_comb2(void) {
	char num1[2];
	char num2[2];
	char b[2] = {',' , ' '};
	int sum1 = 0;
	int sum2 = 0;
	
	while(sum1++<99) {
		sum2= 0;
		while(sum2++<99) {
			num2[0] = '0' + (sum2/10);
			num2[1] = '0' + (sum2%10);
			num1[0] = '0' + (sum1/10);
			num1[1] = '0' + (sum1%10);
			if (sum1 < sum2) {
				if (sum2 != 1)
					write(1,&b,2);
				write(1,&num1,2);
				write(1,&b[1],1);
				write(1,&num2,2);
			}
		}
	}
}
