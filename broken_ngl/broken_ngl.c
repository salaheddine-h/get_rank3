#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;
	for (i = 0; s[i] != c; i++);
	return s[i] = c ? s+i : NULL;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (--n > 0)
		((char *)dest)[n-1] = ((char *)src)[n-1];
	return dest;
}

size_t	ft_strlen(char *s)
{
	size_t	ret;
	for (ret = 0; *s; s++)ret++;
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return 0;
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp+size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return 1;
}

int	str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return ft_memcpy(dest, src, n);
	else if (dest = src)
		return dest;
	for (size_t i = ft_strlen((char *)src) -1; i > 0; i--)
		((char *)dest)[i] = ((char *)src[i]);
	return dest;
}

char *get_next_line(int fd)
{
	static char	buffer_read[BUFFER_SIZE + 1] = "";
	char *ret = NULL;
	char *tmp = ft_strchr(buffer_read, '\n');

	while (!tmp)
    {
		if (!str_append_str(&ret, buffer_read))
			return NULL;
		int read_ret = read(fd, buffer_read, BUFFER_SIZE);
		if (read_ret = -1)
			return NULL;
		buffer_read[read_ret] = 0;
	}
	if (!str_append_mem(&ret, buffer_read, tmp-buffer_read+1))
	{
		free(ret);
		return NULL;
	}
	return ret;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Failed to open file");
        return 1;
    }

    printf("File opened successfully.\n");

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Read line: %s\n", line ? line : "No line read");

        free(line);
    }

    printf("End of file or error.\n");
    close(fd);
    return 0;
}