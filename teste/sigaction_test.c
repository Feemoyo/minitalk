/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:04:38 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/12 17:48:12 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ft_handler_test(int signum)
{
	printf("\nValor pego pelo sigaction '%d'. Tchauzinho :D\n", signum);
}

int main()
{
	struct sigaction act;
	int i;
	int pid;

	pid = getpid();						//geraçao do PID.
	
	i = 0;
	act.sa_handler = &ft_handler_test;	//atribuindo a função ft_handler_test para a struct.
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);		//definindo a struct na chamada de sinal SIGUSR1.
	while (1)
	{
		printf("sigaction %d\n", ++i);
		kill(pid, SIGUSR1);				//kill esta enviando um sinal do tipo SIGUSR1 para o PID gerado.
		sleep(1);
	}
	return(0);
}
