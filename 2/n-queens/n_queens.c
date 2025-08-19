#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	print_solution(int *queens, int n)
{
	for(int i = 0; i < n; i++)
	{
		char c = queens[i] + '0';
		write(1, &c, 1);
		if(i < n - 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int is_safe(int *queens, int col, int row)
{
	for(int i = 0; i < col; i++)
	{
		if(queens[i] == row)
			return(0);
		if((col - i) == (row > queens[i] ? row - queens[i] : queens[i] - row))
			return(0);
	}
	return(1);
}

void	solve(int *queens, int col, int n)
{
	if(col == n)
	{
		print_solution(queens, n);
		return;
	}
	int row = 0;
	while(row < n)
	{
		if(is_safe(queens, col, row))
		{
			queens[col] = row;
			solve(queens, col + 1, n);
		}
		row++;
	}
}
int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	int n = atoi(argv[1]);
	if(n <= 0)
		return(1);
	int queens[n];
	solve(queens, 0, n);
	return(0);
}