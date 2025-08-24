#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void		sort(char *str, int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = i + 1; j < len; j++)
		{
			if(str[i] > str[j])
			{
				char c = str[i];
				str[i] = str[j];
				str[j] = c;
			}
		}
	}
}
void		permitation(char *str, char *res, int *use, int len , int idx)
{
	if(idx == len)
	{
		puts(res);
		return;
	}

	for(int i = 0; i < len; i++)
	{
		if(use[i])
			continue;
		use[i] = 1;
		res[idx] = str[i];
		permitation(str, res, use, len, idx + 1);
		use[i] = 0;
	}
}
int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	int len = 0;
	while(argv[1][len])
		len++;
	int *use = calloc(len, sizeof(int));
	char *res = malloc(len + 1);

	if(!res || !use)
	{
		free(use);
		free(res);
		return(1);
	}
	sort(argv[1], len);
	permitation(argv[1], res, use, len , 0);
	free(use);
	free(res);
	return(0);
}
