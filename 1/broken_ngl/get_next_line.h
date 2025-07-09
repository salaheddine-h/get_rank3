#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

// #define BUFFER_SIZE 1024

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
size_t	ft_strlen(char *s);
int	str_append_mem(char **s1, char *s2, size_t size2);
int	str_append_str(char **s1, char *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif