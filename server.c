/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:10:46 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/16 03:40:50 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_welcome(int *count, int *value, char bit)
{
	if (*count == 1 && bit == 1)
	{
		*value = 0;
		*value = *value + 1;
	}
	else if (*count == 2 && bit == 1) //01100001 1 + 32 + 64
		*value = *value + 2;
	else if (*count == 3 && bit == 1)
		*value = *value + 4;
	else if (*count == 4 && bit == 1)
		*value = *value + 8;
	else if (*count == 5 && bit == 1)
		*value = *value + 16;
	else if (*count == 6 && bit == 1)
		*value = *value + 32;
	else if (*count == 7 && bit == 1)
		*value = *value + 64;
	else if (*count == 8)
	{
		ft_putnbr_fd((int)*value, 1);
		write(1, " ", 1);
		ft_putchar_fd((unsigned char )*value, 1);
		*count = 0;
		*value = 0;
	}
	//ft_putnbr_fd(*count, 1);
	//write(1, "\n", 1);
}

void ft_handler(int signum)
{
	static int count;
	static int value;
	
	if(signum == 10) // SIGUSR1 == 0
	{
		count = count + 1;
		ft_welcome(&count, &value, 0);
	}
	else if(signum == 12) // SIGUSR2 == 1
	{
		count = count + 1;
		ft_welcome(&count, &value, 1);
	}
	//kill(info->si_pid, SIGUSR1);
	/*if(count > 7)
		{
			ft_putchar_fd((unsigned char)value, 1);
			count = 0;
		} */
}

int main()
{
	struct sigaction act;
	int pid;
    pid = getpid();

	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	act.sa_handler = &ft_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (42)
		sleep(1);
    return 0;
}
