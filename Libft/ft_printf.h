/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:02 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/25 18:55:35 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
/* In standard C lib., used inside: printf, scanf
providing va_list type and macros: va_start, 
va_list, va_arg, va_end*/
# include <unistd.h>
/* in libc for UNIX standard - POSIX input/ouput, file...
read, write, close, lseek, , access, unlink, chdir, 
fork, exec, getpid, exit, STDIN_FILENO, STDOU_FILENO, 
STDERR_FILENO, getcwd, sleep, alarm */
# include <stddef.h>
# include <stdlib.h>
/* for NULL */
//# include <stdio.h>

typedef struct s_formats
{
	int	minus;
	int	zero;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	sign;
	int	len_digit;
	int	len_total;
	int	err;
}	t_formats;

/* "cspdiuxX%" flags for mandatory */
/* "-0.# +" flags for bonus */
/* two numbers for length-width */
/* sign for printing sign or not*/

int		ft_printf(const	char *s_in, ...);
int		print_types(va_list ap, t_formats *formats, char **s);
void	get_flags(t_formats *formats, char **s);
void	get_width_prcn(int *width, char **s);
int		print_c(char c, t_formats *formats);
int		print_s(char *s, t_formats *formats);
int		print_p(unsigned long p, t_formats *formats);
int		print_di(int n, t_formats *formats);
int		print_di1(t_formats *formats, int n);
int		print_di2(t_formats *formats, int n);
int		print_di3(t_formats *formats, int n);
int		print_di4(t_formats *formats, int n);
int		print_u(unsigned int u, t_formats *formats);
int		print_x(unsigned int x, t_formats *formats, char c);
int		print_precision(t_formats *formats, int no_digit);
int		print_width(t_formats *formats, int len_total, char c);
int		print_sign(t_formats *formats, int n);
void	print_hex(unsigned long n, char x, t_formats *formats, int *np);
int		print_0x(t_formats *formats, char c, unsigned int x);
int		len_s_base(unsigned long n, int base);
int		len_uint(unsigned int n, t_formats formats, int base);
int		len_int(int n);
int		totalize_len(int n, int no_digit, t_formats *formats);
int		total_len(int precision, int len_u);
void	ft_putpnbr(unsigned int n, t_formats *formats, int *np);
void	ft_putnbr(long n, int *p_np, int *err);
int		ft_putxstr(char *s, int len, int *err);
int		ft_putnchar(char c, int n, int *err);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif