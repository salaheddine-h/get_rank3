#include "get_next_line.h"

int str_append_mem(char **s1, char *s2, size_t  size2)
{
    size_t  size1 = (*s1) ? ft_strlen(*s1) : 0;
    char    *temp = malloc(size1 + size2 + 1);

    if(!temp)
        return(0);
    if(*s1)
    {
        ft_memcpy(temp, *s1, size1);
        free(*s1);
    }
    ft_memcpy(temp + size1, s2, size2);
    temp[size1 + size2] = '\0';

    *s1 = temp;
    return(1);
}
void    *ft_memcpy(void *dest, const void *src, size_t  n)
{
    while(n--)
        ((char *)dest)[n] = ((char *)src)[n];
    return(dest);
}
size_t  ft_strlen(char *str)
{
    size_t  len = 0;
    while(str[len])
        len++;
    return(len);
}
char    *get_next_line(int fd)
{
    static char buffer_read[BUFFER_SIZE + 1] = {0};
    static int  buffer_len = 0;
    static int  buffer_pos = 0;
    ssize_t read_byte;
    char    *LINE = NULL;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while(1)
    {
        if(buffer_pos < buffer_len)
        {
            char    c = buffer_read[buffer_pos++];
            if(!str_append_mem(&LINE, &c, 1))
            {
                free(LINE);
                return(NULL);
            }
            if(c == '\n')
                return(LINE);
        }
        else
        {
            read_byte = read(fd, buffer_read, BUFFER_SIZE);
            if(read_byte < 0)
            {
                free(LINE);
                return(NULL);
            }
            if(read_byte == 0)
            {
                if(LINE)
                    return(LINE);
                return(NULL);
            }
            buffer_pos = 0;
            buffer_len = read_byte;
        }
    }
}


