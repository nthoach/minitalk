/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:23:34 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/16 17:26:07 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*send a character by sending bit by bit starting from most-valueed bit to 
the least one, SIGUSR1 will send 1 and SIGUSR2 will sent 0 */

void	send_char(int server_pid, char ch)
{
	int	bit;
	int	one;

	bit = 0;
	one = 0b10000000;
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

/* send the whole string char by char, send newline and zero
char to mark the end */

void	send_string(int server_pid, char *msg)
{
	while (*msg)
	{
		send_char(server_pid, *msg);
		msg++;
	}
	if (!*msg)
	{
		send_char(server_pid, '\n');
		send_char(server_pid, '\0');
	}
}

/*receiving back signal from the server
if SIGUSR1 means server recevieed and prince out the result
if not SIGUSR1 (SIGUSR2) mean counting  the bytes
the variabe "bt_ct" is set at zero with the main program, counting up at every
time the server send SIGUSR2 as it printing a char - 1 byte
total bytes sent is by_ct - 1 because we exculude the additioanl '\n' */

void	recv_print(int sign)
{
	static int	by_ct;

	if (sign == SIGUSR1)
	{
		ft_printf("Message received.\n%d bytes.\n", (by_ct - 1));
		exit(0);
	}
	else if (sign == SIGUSR2)
		by_ct++;
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
