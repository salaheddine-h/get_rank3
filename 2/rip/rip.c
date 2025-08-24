#include "rip.h"


void	print_soluiton(char *str)
{
	for(int i  = 0; str[i]; i++)
	{
		write(1, &str[i], 1);
	}
	write(1, "\n", 1);
}
void	solve(char *str, int pos, int open, int to_remove, char *temp, int temp_pos)
{
	if(!str[pos])
	{
		if(open == 0 && to_remove == 0)
		{
			temp[temp_pos] = '\0';
			print_soluiton(temp);
		}
		return;
	}

	char	current = str[pos];
	if(current != '(' && current != ')')
	{
		temp[temp_pos] = current;
		solve(str, pos + 1, open, to_remove, temp, temp_pos + 1);
		return;
	}

	if(to_remove > 0)
	{
		temp[temp_pos] = '_';
		solve(str, pos + 1, open , to_remove - 1, temp, temp_pos + 1);
	}

	if(current == '(')
	{
		temp[temp_pos] = '(';
		solve(str, pos + 1, open + 1, to_remove, temp, temp_pos + 1);
	}

	else if(current == ')')
	{
		if(open > 0)
		{
			temp[temp_pos] = ')';
			solve(str, pos + 1, open - 1, to_remove, temp, temp_pos + 1);
		}
	}
}

int get_min_remove(char *str)
{
	int open = 0;
	int close = 0;
	int i = 0;

	while(str[i])
	{
		if(str[i] == '(')
			open++;
		else if(str[i] == ')')
		{
			if(open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return(open + close);
}

int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	int n = 0;
	while(argv[1][n])
		n++;
	char temp[n + 1];
	int min_remove = get_min_remove(argv[1]);
	solve(argv[1], 0,  0, min_remove, temp, 0);
	return(0);
}
