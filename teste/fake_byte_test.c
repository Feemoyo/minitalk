/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_byte_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:01:58 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/13 15:59:50 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct build_byte_s
{
	//unsigned char bt;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
	unsigned char b8:1;
}	build_byte_t;

int main()
{
	build_byte_t b;
	int d;
	
	d = 100;
	/*b.b1 = 1;
	b.b2 = 0;
	b.b3 = 0;
	b.b4 = 0;
	b.b5 = 0;
	b.b6 = 0;
	b.b7 = 1;
	b.b8 = 0;*/
	*(unsigned char *)&b = (unsigned char)'a';
	size_t sla;
	sla = (char);
	printf("%ld", sla);
	//write(1, &b, 1);
	printf("\n");
	/*
	printf("Endereço da struct: %p\n\n", &b);
	printf("Endereço do bt: %p\n", &b.bt);
	//printf("Endereço do b1: %p\n", &b.b1); */
		
}