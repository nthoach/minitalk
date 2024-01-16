/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:45:15 by damachad          #+#    #+#             */
/*   Updated: 2024/01/16 17:32:08 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*send char each bit, 1 for SIGUSR1 and - for SIGUSR2
send highest-value bit first., each bit send will be delay 50 us
to ensure data transfer without loss*/

void	send_char(char ch, int server_pid)
{
	int				bit;
	unsigned char	one;

	bit = 0;
	one = 0b10000000;
	while (bit <= 7)
	{
		if (ch & one)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		one >>= 1;
		bit++;
		usleep(50);
	}
}

/*Process and validate number of arguments and send the message to the
send_bits function*/

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char(argv[2][i], server_pid);
			i++;
		}
		send_char('\n', server_pid);
	}
	else
	{
		ft_printf("Number of arguments should be 2.\n");
		ft_printf("e.g: ./client [PID no] [message]\n");
		return (1);
	}
	return (0);
}
