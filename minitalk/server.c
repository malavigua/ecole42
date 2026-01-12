/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:37:56 by malmany           #+#    #+#             */
/*   Updated: 2026/01/12 19:09:35 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	if (signum == 10)
		printf("Received  SIGUSR1 %d\n", signum);
	else if (signum == 12)
		printf("Received  SIGUSR2 %d\n", signum);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	printf("%d\n", getpid());
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
