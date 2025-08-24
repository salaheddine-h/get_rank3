#include <unistd.h>
#include <stdlib.h>

void	print_solution(int *queen, int n)
{
	for(int i = 0; i < n; i++)
	{
		char c = queen[i] + '0';
		write(1, &c, 1);
		if(i < n - 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
int	is_safe(int *queen, int col, int row)
{
	for(int i = 0; i < col; i++)
	{
		if(queen[i] == row)
			return(0);
		if((col - i) == (row > queen[i] ? row - queen[i] : queen[i] - row))
			return(0);
	}
	return(1);
}

void	solve(int *queen, int col, int n)
{
	if(col == n)
	{
		print_solution(queen, n);
		return;
	}
	for(int row = 0; row < n; row++)
	{
		if(is_safe(queen, col, row))
		{
			queen[col] = row;
			solve(queen, col + 1, n);
		}
	}
}
int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	int len = atoi(argv[1]);
	if(len <= 0)
		return(1);
	int queens[len];
	solve(queens, 0, len);
	return(0);
}