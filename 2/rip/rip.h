#ifndef RIP_H
#define RIP_H

#include <unistd.h>
#include <stdio.h>

void  print_soltion(char *str);
void	solve(char *str, int pos, int open, int to_remove, char *temp, int temp_pos);
int	get_min_remove(char *str);

#endif
