/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:23:34 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/15 20:22:28 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk_bonus.h"

/*send a character by sending bit by bit starting from most-valueed bit to the least
SIGUSR1 will send 1 and SIGUSR2 will sent 0 */

void	send_char(int server_pid, char ch)
{
	int	bit;
	int	one;

	bit = 0;
	one = 128;
	while (bit++ < 8)
	{
		if (ch & one)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_printf("Error: Unable to send SIGUSR1.\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_printf("Error: Unable to send SIGUSR2.\n");
		}
		one >>= 1;
		usleep(50);
	}
}

/* send .*/

void	send_string(int server_pid, char *msg)
{
//	int				bit;
//	unsigned char	z;

	while (*msg)
	{
		send_char(server_pid, *msg);
		// bit = 0;
		// z = 128;
		// while (bit++ < 8)
		// {
		// 	if (*msg & z)
		// 		kill(server_pid, SIGUSR1);
		// 	else
		// 		kill(server_pid, SIGUSR2);
		// 	z >>= 1;
		// 	usleep(100);
		// }
		msg++;
	}
	if (!*msg)
	{
		send_char(server_pid, '\n');
		send_char(server_pid, '\0');
	}
}

/*Create a counter for every character printed and, when 
full message is received by the server, print the counter*/

void	recv_print(int sign)
{
	static int	count;

	if (sign == SIGUSR1)
	{
		ft_printf("Message received.\n%d bytes.\n", (count - 1));
		exit(0);
	}
	else
		count++;
}

/*Validate number of arguments and send the message to the send_bits function*/

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	if (argc == 3)
	{
		sa.sa_handler = &recv_print;
		sa.sa_flags = SA_SIGINFO;
		server_pid = ft_atoi(argv[1]);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_string(server_pid, argv[2]);
	}
	else
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Usage: ./client [server PID] [message]\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
