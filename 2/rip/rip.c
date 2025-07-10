#include "rip.h"

int	check_len1(char *str)
{
	int	i = 0;
	int	len = 0;
	while(str[i])
	{
		if(str[i] == ')')
			len++;
		i++;
	}
	return(len);
}
int	check_len2(char *str)
{
	int	i = 0;
	int	len = 0;
	while(str[i])
	{
		if(str[i] == '(')
			len++;
		i++;
	}
	return(len);
}

size_t	ft_strlen(char *str)
{
	size_t	len = 0;
	while(str[len])
		len++;
	return(len);
}

char	*read_buffer(char *str)
{
	int	len = ft_strlen(str);
	char	*buff;
	int	i;

	buff = malloc(len + 1);
	if(!buff)
	{
		printf("malloc is failed !!\n");
		return(NULL);
	}
	i = 0;
	while(str[i])
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return(buff);
}

void	replace(char *str)
{
	int	i = 0;
	int	j;

	while(str[i])
	{
		for(j = 0; s[j] && str[i + j] == s[j]; j++);
		if(j == len)
		{
			for(j = 0; j < len; j++)
				str[i + j] = ' ';
			i += len;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	char	*buffer;
	int	len_q1 = 0;
	int	len_q2 = 0;

	if(argc != 2 || !argv[1][0])
		return(1);
	len_q1 = check_len1(argv[1]);
	len_q2 = check_len2(argv[1]);

	buffer = read_buffer(argv[1]);
	if(!buffer)
	{
		printf("function read_input is failed \n");
		return(1);
	}
	printf("old buffer = %s\n", buffer);
	replace(buffer);
	printf("new buffer = %s\n", buffer); 
	printf("len_q1 = %d\n", len_q1);
	printf("len_q2 = %d\n", len_q2);
	return(0);

}
