#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024;

char    *get_next_line(int fd);
void    *ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlen(char *str);
int     str_append_mem(char **s1, char **s2, size_t size2);
int     str_append_str(char **s1, char **s2);
void    *ft_memmove(void *dest, const void *src, size_t n);

#endif