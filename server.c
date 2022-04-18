/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:10:46 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/18 13:20:19 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_set_bit(t_byte_struct *c, int i, int bit)
{
	if (bit == 0)
		c->bit1 = i;
	else if (bit == 1)
		c->bit2 = i;
	else if (bit == 2)
		c->bit3 = i;
	else if (bit == 3)
		c->bit4 = i;
	else if (bit == 4)
		c->bit5 = i;
	else if (bit == 5)
		c->bit6 = i;
	else if (bit == 6)
		c->bit7 = i;
	else if (bit == 7)
		c->bit8 = i;
}

void	ft_check_end_of_string(unsigned char *c)
{
	if (*c == '\0')
	{
		write(1, "\n", 1);
	}
}

void	ft_signal_handler(int num, siginfo_t *info, void *ctx)
{
	static t_byte_struct	c;
	static int				count;

	if (num == SIGUSR1)
		ft_set_bit(&c, 0, count);
	else if (num == SIGUSR2)
		ft_set_bit(&c, 1, count);
	if (count == 7)
	{
		count = 0;
		write(1, (unsigned char *)&c, 1);
		ft_check_end_of_string((unsigned char *)&c);
	}
	else
		count++;
	if (kill(info->si_pid, SIGUSR2))
		exit (1);
	(void)ctx;
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	sa.sa_mask = mask;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL))
		exit (1);
	if (sigaction(SIGUSR2, &sa, NULL))
		exit (1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
