/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:20:43 by malmany           #+#    #+#             */
/*   Updated: 2026/01/13 18:15:10 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	mul;

	res = 0;
	i = 0;
	mul = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			mul *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * mul);
}

void	send_signal(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	signal_handler(int signum)
{
	printf("%d received\n", signum);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	pid_t				pid;
	char				*msg;
	int					i;

	i = 0;
	if (argc != 3)
		return (1);
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	printf("%d\n", getpid());
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (msg[i])
	{
		send_signal(pid, msg[i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
