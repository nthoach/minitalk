/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:19:41 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/11 16:21:03 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle(int signo, siginfo_t *info, void *context)
{
	static int	bit;
	static int	character;

	(void)context;
	if (signo == SIGUSR1)
		character += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (character == '\0')
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_printf("Error on sending SIGUSR1 \n");
		}
		if (character != '\0')
		{
			ft_putchar_fd(character, 1);
			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Process Indentifier (PID) of the Sever: %d\n", getpid());
	sa.sa_sigaction = &handle;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error on setting up signal: SIGUSR1\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error on setting up signal: SIGUSR2\n");
		return (2);
	}
	while (1)
		pause();
	return (0);
}
