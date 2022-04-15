/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:39:47 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/15 23:14:32 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_despatch(int pid, int bit)
{
	if (bit == 0)
	{
		//printf("bit: %d\n", bit);
		kill(pid, SIGUSR1);
		//sleep(0.00009);
	}
	else if (bit == 1)
	{
		//printf("bit: %d\n", bit);
		kill(pid, SIGUSR2);
		//sleep(0.00009);
	}
	sleep(0.01);
}

void ft_lobby(int pid, t_fake_byte byte)
{
	ft_despatch(pid, byte.bit1);
	ft_despatch(pid, byte.bit2);
	ft_despatch(pid, byte.bit3);
	ft_despatch(pid, byte.bit4);
	ft_despatch(pid, byte.bit5);
	ft_despatch(pid, byte.bit6);
	ft_despatch(pid, byte.bit7);
	ft_despatch(pid, byte.bit8);
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