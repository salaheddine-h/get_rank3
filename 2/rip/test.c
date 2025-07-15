#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_solution(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        write(1, &str[i], 1);
    }
    write(1, "\n", 1);
}

int get_min_removals(char *str)
{
    int open = 0, close = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
    }
    return open + close;
}

void solve(char *str, int pos, int open, int to_remove, char *temp, int temp_pos)
{
    // Base case: reached end of string
    if (!str[pos])
    {
        if (open == 0 && to_remove == 0)
        {
            temp[temp_pos] = '\0';
            print_solution(temp);
        }
        return;
    }

    // Current character
    char current = str[pos];

    // If it's not a parenthesis, just copy it
    if (current != '(' && current != ')')
    {
        temp[temp_pos] = current;
        solve(str, pos + 1, open, to_remove, temp, temp_pos + 1);
        return;
    }

    // Try removing current parenthesis (replace with space)
    if (to_remove > 0)
    {
        temp[temp_pos] = ' ';
        solve(str, pos + 1, open, to_remove - 1, temp, temp_pos + 1);
    }

    // Try keeping current parenthesis
    if (current == '(')
    {
        temp[temp_pos] = '(';
        solve(str, pos + 1, open + 1, to_remove, temp, temp_pos + 1);
    }
    else if (current == ')' && open > 0)
    {
        temp[temp_pos] = ')';
        solve(str, pos + 1, open - 1, to_remove, temp, temp_pos + 1);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    int n = strlen(argv[1]);
    char temp[n + 1];
    int min_removals = get_min_removals(argv[1]);

    solve(argv[1], 0, 0, min_removals, temp, 0);
    return 0;
}

/*
TEST CASES:

1. Basic unbalanced:
./rip '(()'
Expected:
 ()
( )

2. Complex case:
./rip '((()()())()'
Expected:
((()()()))

3. Multiple solutions:
./rip '()(())())'
Expected:
()( )()
()( )()
( )()()

4. Only closing:
./rip ')))'
Expected:


5. Only opening:
./rip '((('
Expected:


6. Already balanced:
./rip '()()'
Expected:
()()

7. Empty or single:
./rip '('
Expected:


8. Complex from subject:
./rip '(()(()('
Expected multiple solutions with spaces

Compile: gcc -Wall -Wextra -Werror -o rip rip.c
Test: ./rip 'test_case' | cat -e
*/

void	print_solution(char *str)
{
	for(int i = 0; str[i]; i++)
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
			temp[t]
		}
	}
}
int	get_min_removals(char *str)
{
	int	open = 0;
	int	close = 0;

	for(int i = 0; str[i]; i++)
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
	}
	return(open + close);
}

int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	int	n = ft_strlen(argv[1]);
	int	temp[n + 1];
	int min_removals = get_min_removals(argv[1]);
	solvew(argv[1], 0, 0, min_removals, temp, 0);
	return(0);
}