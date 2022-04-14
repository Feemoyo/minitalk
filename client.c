/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:39:47 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/14 19:14:43 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_despatch(int pid, int bit, int count)
{
	if (bit == 0)
	{
		printf("bit: %d\n", bit);
		kill(pid, SIGUSR1);
		sleep(0.00001);
	}
	if (bit == 1)
	{
		printf("bit: %d\n", bit);
		kill(pid, SIGUSR2);
		sleep(0.00001);
	}
}

void ft_lobby(int pid, t_fake_byte byte)
{
	static int count;
	
	count = 1;
	if (count++ == 1)
		ft_despatch(pid, byte.bit1, count);
	if (count++ == 2)
		ft_despatch(pid, byte.bit2, count);
	if (count++ == 3)
		ft_despatch(pid, byte.bit3, count);
	if (count++ == 4)
		ft_despatch(pid, byte.bit4, count);
	if (count++ == 5)
		ft_despatch(pid, byte.bit5, count);
	if (count++ == 6)
		ft_despatch(pid, byte.bit6, count);
	if (count++ == 7)
		ft_despatch(pid, byte.bit7, count);
	if (count == 8)
	{
		ft_despatch(pid, byte.bit8, count);
		count = 1;
	}
}

int main(int argc, char **argv)
{
	int i;
	t_fake_byte byte;

	i = 0;
	while (argv[2][i] != 0)
		{
			*(unsigned char *)&byte = argv[2][i];
			ft_lobby(ft_atoi(argv[1]), byte);
			i++;
		}
	return (0);
}