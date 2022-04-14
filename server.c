/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:10:46 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/14 20:55:06 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_welcome(int *count, int *value)
{
	if (*count == 1)
		*value = *value + 1;
	else if (*count == 2)
		*value = *value + 2;
	else if (*count == 3)
		*value = *value + 4;
	else if (*count == 4)
		*value = *value + 8;
	else if (*count == 5)
		*value = *value + 16;
	else if (*count == 6)
		*value = *value + 32;
	else if (*count == 7)
		*value = *value + 64;
	else if (*count == 8)
		*value = *value + 128;
	//printf("'char': %d %c\n", *value, *value);
}

void ft_handler(int signum)
{
	static int count;
	int value;
	
	if(!count || count > 8)
	{
		value = 0;
		count = 1;
	}
	/*if(!value || value > 127)
		value = 0; */
	//printf("count: %d\n", count);
	if(signum == 10)
	{
		//printf("sigusr1\n");
		count = count + 1;
	}
	else if(signum == 12)
	{
		//printf("sigusr2\n");
		ft_welcome(&count, &value);
		count = count + 1;
	}
	if(count >= 8)
		{
			ft_putchar_fd((unsigned char)value, 1);
			count = 0;
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
