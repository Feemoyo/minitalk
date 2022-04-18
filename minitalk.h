/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:27:14 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/18 13:19:57 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct byte
{
	unsigned char	bit1:1;
	unsigned char	bit2:1;
	unsigned char	bit3:1;
	unsigned char	bit4:1;
	unsigned char	bit5:1;
	unsigned char	bit6:1;
	unsigned char	bit7:1;
	unsigned char	bit8:1;
}	t_byte_struct;

void	ft_set_bit(t_byte_struct *c, int i, int bit);
void	ft_check_end_of_string(unsigned char *c);
void	ft_signal_handler(int num, siginfo_t *info, void *ctx);
void	ft_onfirm_handler(int sig);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	ft_send_signal(int bit, int pid);
void	ft_convert(int c, int pid);
void	ft_send_zero(int pid);
void	ft_putnbr_fd(int n, int fd);
void	ft_usage(void);
#endif