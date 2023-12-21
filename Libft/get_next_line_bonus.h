/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:27:27 by nthoach           #+#    #+#             */
/*   Updated: 2023/11/25 17:01:57 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h> 
/* file control: open() O_RDONLY, O_WRONLY, O_RDWR
, O_CREAT, O_TRUNC, O_APPEND, O_EXCL, O_NONBLOCK */
# include <stdint.h> 
/* typedefs with fixed byte for different platforms */
# include <stdio.h>
/* standard input-output: fopen(), fclose, fprintf, fsccanf
fwrite, fread, printf(), scanf(), putchar(), getchar(), perror()
FILE */
# include <stdlib.h>
/* standard library: malloc, calloc, realloc, free, 
 rand, srand, exit, atoi, atol, atoll, strtol, stroll, abort,
 atexit, system, getenv */
# include <unistd.h>
/* system calls and POSIX OS functionalities: read, write,
 close, lseek, dup(), dup2, fork, exec, wait, waitpid, exit,
 chdir, getcwd, opendir, readdir, closedir, symlink, readlink, sleep
 alarm, pip*/
size_t	gnl_len(char	*s);
void	gnl_bzero(void *s, size_t n);
void	*gnl_calloc(size_t count, size_t size);
char	*add_text(char *store_in, char *buffer);
size_t	gnl_strchr(char	*buffer, char chr);
char	*extract_line(char *store_text);
char	*read_line(char	*store_text, int fd);
char	*get_next_line(int fd);

#endif