// #include <unistd.h>
// #include <stddef.h>
// #include <stdio.h>

// #define BUFFER_SIZE 1024

// int	ft_strlen(char *str)
// {
// 	int	i = 0;
// 	while(str[i])
// 		i++;
// 	return(i);
// }

// void	replace_src(char *str, int replace_len)
// {
// 	int	i = 0;
// 	while(i < replace_len)
// 	{
// 		str[i] = '*';
// 		i++;
// 	}
// }

// int	check_replace(char *str, char *replace)
// {
// 	int	i = 0;

// 	while(str[i] && replace[i])
// 	{
// 		if(str[i] && str[i] != replace[i])
// 			return(0);
// 		i++;
// 	}
// 	return(1);
// }
// void	filltring(char	*str, char *replace, int src_len)
// {
// 	int	replace_len = ft_strlen(replace);
// 	int	i = 0;

// 	while(str[i])
// 	{
// 		if(check_replace(&str[i], replace))
// 		{
// 			replace_src(&str[i], replace_len);
// 			i += replace_len;
// 		}
// 		else
// 			i++;
// 	}

// }
// int	main(int argc, char **argv)
// {
// 	char	buffer_read[BUFFER_SIZE + 1];
// 	ssize_t	read_byte;

// 	if(argc != 2)
// 		return(1);
// 	while(1)
// 	{
// 		read_byte = read(0, buffer_read, BUFFER_SIZE);
// 		if(read_byte > 0)
// 		{
// 			filltring(buffer_read, argv[1], read_byte);
// 			write(1, buffer_read, read_byte);
// 		}
// 		else if(read_byte == 0)
// 			break;
// 		else
// 		{
// 			write(1, "Error: ", 7);
// 			perror("");
// 			return(1);
// 		}
// 	}
// 	return(0);
// }




#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while(str[i])
		i++;
	return(i);
}
char	*ft_strdup(char *str)
{
	int	i = 0;
	while(str[i])
		i++;
	char	*ptr = malloc(i + 1 *(sizeof(char)));
	if(!ptr)
		return(NULL);
	i = 0;
	while(str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return(ptr);
}

char	*get_next_line(int fd)
{
	static char buffer_read[BUFFER_SIZE];
	static char	line[70000];
	static int	read_num;
	static int	copy_pos;
	int	i = 0;

	if(fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	while(1)
	{
		if(copy_pos >= read_num)
		{
			read_num = read(fd, buffer_read, BUFFER_SIZE);
			copy_pos = 0;
			if(read_num < 0)
				break;
		}
		line[i++] = buffer_read[copy_pos++];
		if(line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if(i == 0)
		return(NULL);
	return(ft_strdup(line));
}

int	check_replace(char *str, char *replace)
{
	int	i = 0;
	while (str[i] && replace[i])
	{
		if(str[i] && str[i] != replace[i])
			return(0);
		i++;
	}
	return(0);
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

void	replace_src(char *str, int replace_len)
{
	int	i = 0;
	while(i < replace_len)
	{
		str[i] = '*';
		i++;
	}
}
int	main(int argc, char **argv)
{
	static char	buffer_read[BUFFER_SIZE + 1];
	ssize_t	read_byte;
	int	i = 0;
	if(argc != 2)
		return(1);
	while(1)
	{
		read_byte = get_next_line(0);
		if(read_byte >= 0)
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
