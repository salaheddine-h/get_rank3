#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>     // for open
#include <unistd.h>    // for close, read
#include <stdlib.h>    // for free
#include <stdio.h>     // for printf

char  *get_next_line(int fd);
int str_append_mem(char **s1, char *s2, size_t  size2);
size_t  ft_strlen(char *str);
void  *ft_memcpy(void *dest, const void *src, size_t  n);

#endif
