/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:20:43 by malmany           #+#    #+#             */
/*   Updated: 2026/01/13 18:54:34 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

pid_t	g_client_pid;

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 10)
		ft_putnbr_fd(n / 10, fd);
	a = n % 10 + '0';
	write(fd, &a, 1);
}

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int				nb_bits;

	(void)ucontext;
	if (!g_client_pid)
		g_client_pid = info->si_pid;
	else if (g_client_pid != info->si_pid)
		return ;
	if (signum == 10)
		c |= (1 << nb_bits);
	nb_bits++;
	if (nb_bits == 8)
	{
		if (c == '\0')
		{
			g_client_pid = 0;
			write(1, "\n", 1);
		}
		else
			write(1, &c, 1);
		nb_bits = 0;
		c = '\0';
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void)argc;
	(void)argv;
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
