/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:10:46 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/13 21:29:54 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//char *str;

void ft_welcome(int *count, int *value)
{
	if (*count == 1)
		value = value + 1;
	if (*count == 2)
		value = value + 2;
	if (*count == 3)
		value = value + 4;
	if (*count == 4)
		value = value + 8;
	if (*count == 5)
		value = value + 16;
	if (*count == 6)
		value = value + 32;
	if (*count == 7)
		value = value + 64;
	if (*count == 8)
		value = value + 128;
}

void ft_handler(int signum)
{
	static int count;
	int naosei;
	int value;
	
	if (!count)
		count = 1;
	if (!value)
		value = 0;
	if(signum == 10)
	{
		ft_welcome(&count, &value);
		count++;
	}
	if(signum == 12)
		count++;
	if (count == 8);
		{
			printf("valor de value: %d\n", value);
			ft_putchar_fd((unsigned char)value, 1);
			count = 1;
		}
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
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (42)
		sleep(1);
    return 0;
}
