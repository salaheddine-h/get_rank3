#include <unistd.h>

int	main(int argc, char **argv)
{
	int	tab[256] = {0};
	int	i;
	int	c;

	i = 0;
	if(argc == 3)
	{
		while(argv[2][i])
		{
			c = argv[2][i];
			tab[c] = 1;
			i++;
		}
		i = 0;
		while(argv[1][i])
		{
			c = argv[1][i];
			if(tab[c] = 1)
			{
				write(1, &c, 1);
				tab[c] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
