/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:06:31 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/12 15:29:28 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ft_handler_test(int signum)
{
	printf("\nValor pego pelo signal '%d'. Tchauzinho :D\n", signum);
}

int main()
{
	int i;
	int pid;

	pid = getpid();						//geraçao do PID.
	i = 0;
	signal(SIGUSR1, ft_handler_test);	//definindo a funçao ft_handler_test na chamada de sinal SIGUSR1.
	while (1)
	{
		printf("signal %d\n", ++i);
		kill(pid, SIGUSR1);				//kill esta enviando um sinal do tipo SIGUSR1 para o PID gerado.
		sleep(1);
	}
	return(0);
}
