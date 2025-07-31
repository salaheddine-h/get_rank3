//shortest version:

void find_subsets(int *set, int size, int target, int *subset, int subsize, int idx)
{
	if (idx == size)
	{
		int sum = 0;
		for (int i = 0; i < subsize; i++)
			sum += subset[i];
		if (sum == target)
		{
			for (int i = 0; i < subsize; i++)
				printf("%d ", subset[i]);
			printf("\n");
		}
		return;
	}
	subset[subsize] = set[idx];
	find_subsets(set, size, target, subset, subsize + 1, idx + 1);
	find_subsets(set, size, target, subset, subsize, idx + 1);
}

int main(int argc, char **argv)
{
	if (argc < 3)
    return 1;
	int target = atoi(argv[1]);
	int size = argc - 2;
	int *set = malloc(size * sizeof(int));
	int *subset = malloc(size * sizeof(int));
	if (!set || !subset)
  {
    free(set),
    free(subset);
    return 1;
  }

	for (int i = 0; i < size; i++)
		set[i] = atoi(argv[i + 2]);
	find_subsets(set, size, target, subset, 0, 0);
	free(set);
  free(subset);
	return 0;
}

gcc -Wall -Werror -Wextra -o powerset powerset.c
valgrind --leak-check=full ./powerset 5 1 2 3 4 5


