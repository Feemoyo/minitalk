/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:39:47 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/18 13:19:04 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_bit_send;

void	ft_confirm_handler(int signum)
{
	g_bit_send = 1;
	(void)signum;
}

void	ft_send_signal(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Problem sending the signal!\n", 29);
			exit(1);
		}
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Problem sending the signal!\n", 29);
			exit(1);
		}
	}
	while (g_bit_send == 0)
		;
	g_bit_send = 0;
}

void	ft_convert(int c, int pid)
{
	t_byte_struct	fake_byte;

	*(unsigned char *)&fake_byte = (unsigned char)c;
	ft_send_signal(fake_byte.bit1, pid);
	ft_send_signal(fake_byte.bit2, pid);
	ft_send_signal(fake_byte.bit3, pid);
	ft_send_signal(fake_byte.bit4, pid);
	ft_send_signal(fake_byte.bit5, pid);
	ft_send_signal(fake_byte.bit6, pid);
	ft_send_signal(fake_byte.bit7, pid);
	ft_send_signal(fake_byte.bit8, pid);
}

void	ft_send_zero(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_send_signal(0, pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_usage();
		exit(1);
	}
	pid = ft_atoi(*(argv + 1));
	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = ft_confirm_handler;
	if (sigaction(SIGUSR2, &sa, NULL))
		exit(1);
	i = 0;
	while (argv[2][i])
	{
		ft_convert((int)argv[2][i], pid);
		i++;
	}
	ft_send_zero(pid);
	return (0);
}
