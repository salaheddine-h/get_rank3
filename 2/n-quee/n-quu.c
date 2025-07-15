#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	print_solution(int *queens, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(queens[i]);
		if (i < n - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int	is_safe(int *queens, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		// Check if queens are in the same row
		if (queens[i] == row)
			return (0);
		// Check diagonal attacks
		if (queens[i] - row == i - col || queens[i] - row == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve_nqueens(int *queens, int col, int n)
{
	int	row;

	if (col == n)
	{
		print_solution(queens, n);
		return;
	}

	row = 0;
	while (row < n)
	{
		if (is_safe(queens, row, col))
		{
			queens[col] = row;
			solve_nqueens(queens, col + 1, n);
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*queens;
	int	i;

	if (argc != 2)
		return (1);

	n = atoi(argv[1]);
	if (n <= 0)
		return (1);

	queens = (int *)malloc(sizeof(int) * n);
	if (!queens)
		return (1);

	i = 0;
	while (i < n)
	{
		queens[i] = -1;
		i++;
	}
	solve_nqueens(queens, 0, n);
	free(queens);
	return (0);
}
