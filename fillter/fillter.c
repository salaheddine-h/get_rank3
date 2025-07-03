// Assignement name : filter

// Expected files : filter.c

// Allowed functions : printf, perror, calloc, malloc, realloc, strlen,
// 					read, free
// -------------------------------------------------------------------------

// Write a program that will take one argument s.

// Your program will then read from stdin and write all the content read in
// stdout except that every occurence of s must be replaced by '*' (as many
// as the length of s).

// For example :

// ./filter bonjour
// will behave the same way as :
// sed 's/bonjour/*******/g'

// ./filter abc
// will behave the same way as :
// sed 's/abc/***/g'

// more generally your program must be the equivalent of the shell script
// filter.sh present in this directory (you can compare your program with
// it)

// In case of error during read or a malloc you must write "Error: "
// followed by the error message in stderr and return 1.

// For example this should work :
// $> echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e
// ***defaaa***de******d***$

// $> echo 'ababcabababc' | ./a.out ababc | cat -e
// *****ab*****$

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
