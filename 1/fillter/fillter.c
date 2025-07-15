#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char	*read_input(void)
{
	char	*buff = malloc(1), tmp;
	int	n;
	int	len = 0;

	if(!buff)
	{
		perror("Error: ");
		return(NULL);
	}
	while((n = read(0, &tmp, 1)) > 0)
	{
		char	*new_buffer = realloc(buff, len + 2);
		if(!new_buffer)
		{
			free(buff);
			perror("Error: ");
			return(NULL);
		}
		buff = new_buffer;
		buff[len++] = tmp;
	}
	if(n < 0)
	{
		free(buff);
		perror("Error: ");
		return(NULL);
	}
	buff[len] = '\0';
	if(len > 0 && buff[len - 1] == '\n')
		buff[len - 1] = '\0';
	return(buff);
}

void	replace(char *str, char *s)
{
	int	i = 0;
	int	j;
	int	len = strlen(s);

	while(str[i])
	{
		for(j = 0; s[j] && str[i + j] == s[j]; j++);
		if(j == len)
		{
			for(j = 0; j < len; j++)
				str[i + j] = '*';
			i += len;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	char	*buffer_read;

	if(argc != 2 || !argv[1][0])
		return(1);
	buffer_read = read_input();
	if(!buffer_read)
		return(1);
	replace(buffer_read, argv[1]);
	printf("%s\n", buffer_read);
	free(buffer_read);
	return(0);
}
