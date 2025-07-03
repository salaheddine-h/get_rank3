#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int	ft_strlen(char *str)
{
	int	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	replace_src(char *str, int replace_len)
{
	int	i = 0;
	while(i < replace_len)
	{
		str[i] = '*';
		i++;
	}
}

int	check_replace(char *str, char *replace)
{
	int	i = 0;

	while(str[i] && replace[i])
	{
		if(str[i] && str[i] != replace[i])
			return(0);
		i++;
	}
	return(1);
}
void	filltring(char	*str, char *replace, int src_len)
{
	int	replace_len = ft_strlen(replace);
	int	i = 0;

	while(str[i])
	{
		if(check_replace(&str[i], replace))
		{
			replace_src(&str[i], replace_len);
			i += replace_len;
		}
		else
			i++;
	}

}
int	main(int argc, char **argv)
{
	char	buffer_read[BUFFER_SIZE + 1];
	ssize_t	read_byte;

	if(argc != 2)
		return(1);
	while(1)
	{
		read_byte = read(0, buffer_read, BUFFER_SIZE);
		if(read_byte > 0)
		{
			filltring(buffer_read, argv[1], read_byte);
			write(1, buffer_read, read_byte);
		}
		else if(read_byte == 0)
			break;
		else
		{
			write(1, "Error: ", 7);
			perror("");
			return(1);
		}
	}
	return(0);
}
