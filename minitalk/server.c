/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:37:56 by malmany           #+#    #+#             */
/*   Updated: 2026/01/13 18:24:38 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_client_pid;

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	nb_bits;

	if (!g_client_pid || g_client_pid == getpid())
		g_client_pid = info->si_pid;
	else if (g_client_pid != info->si_pid || g_client_pid == getpid())
		return ;
	printf("clientPid : %d\n", g_client_pid);
	if (!nb_bits)
		nb_bits = 0;
	if (signum == 10)
		c |= (1 << nb_bits);
	nb_bits++;
	if (nb_bits == 8)
	{
		if (c == '\0')
		{
			//printf("fin message\n");
			g_client_pid = 0;
			printf(" clientPid %d\n", g_client_pid);
			write(1, "\n", 1);
		}
		else
			write(1, &c, 1);
		nb_bits = 0;
		c = '\0';
	}
	if (g_client_pid != getpid())
		kill(g_client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	printf("%d\n", getpid());
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
